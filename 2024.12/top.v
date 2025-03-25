`timescale 1ns / 1ps

module CPU_TOP (
    input clk,          // 全局时钟输入
    input rstn,         // 复位信号（低电平有效）
    input [15:0] sw_i,  // 拨码开关输入
    output [31:0] led_o // LED输出
);

// 时钟分频器
reg [31:0] clkdiv;
wire Clk_CPU;

always @(posedge clk or negedge rstn) begin
    if (!rstn)
        clkdiv <= 0;
    else
        clkdiv <= clkdiv + 1'b1;
end

// 选择 CPU 时钟
assign Clk_CPU = (sw_i[15]) ? clkdiv[27] : clkdiv[25];

// 信号声明
wire [31:0] PC, NPC, instr;
wire [31:0] ALUOut, RF_RD1, RF_RD2, EXT_Imm;
wire Zero;

// 控制信号
wire [4:0] ALUOp;
wire [5:0] EXTOp;
wire RegWrite, MemWrite, MemRead, ALUSrc;
wire [2:0] NPCOp;
wire [2:0] DMType;
wire [1:0] WDSel;

// PC模块
PC U_PC (
    .clk(Clk_CPU),
    .rst(rstn),
    .NPC(NPC),
    .PCwr(sw_i[1]),
    .PC(PC),
    .sw_i(sw_i[5:2])
);

// NPC模块
NPC U_NPC (
    .PC(PC),
    .imm(EXT_Imm),
    .NPCOp(NPCOp),
    .Zero(Zero),
    .NPC(NPC)
);

// 控制模块
ctrl U_CTRL (
    .Op(instr[6:0]),
    .Funct7(instr[31:25]),
    .Funct3(instr[14:12]),
    .Zero(Zero),
    .RegWrite(RegWrite),
    .MemWrite(MemWrite),
    .MemRead(MemRead),
    .EXTOp(EXTOp),
    .ALUOp(ALUOp),
    .NPCOp(NPCOp),
    .ALUSrc(ALUSrc),
    .DMType(DMType),
    .WDSel(WDSel)
);

// 寄存器堆
RF U_RF (
    .clk(Clk_CPU),
    .rst(rstn),
    .RegWrite(RegWrite),
    .A1(instr[19:15]),
    .A2(instr[24:20]),
    .A3(instr[11:7]),
    .WD(led_o),
    .RD1(RF_RD1),
    .RD2(RF_RD2)
);

// 符号扩展模块
EXT U_EXT (
    .iimm(instr[31:20]),
    .simm({instr[31:25], instr[11:7]}),
    .bimm({instr[31], instr[7], instr[30:25], instr[11:8]}),
    .uimm(instr[31:12]),
    .jimm(instr[31:12]),
    .EXTOp(EXTOp),
    .immout(EXT_Imm)
);

// ALU模块
alu U_ALU (
    .A(RF_RD1),
    .B(ALUSrc ? EXT_Imm : RF_RD2),
    .ALUOp(ALUOp),
    .C(ALUOut),
    .Zero(Zero)
);

// 数据存储器
DM U_DM (
    .clk(Clk_CPU),
    .DMWr(MemWrite),
    .addr(ALUOut[5:0]),
    .din(RF_RD2),
    .DMType(DMType),
    .dout(led_o)
);

endmodule
