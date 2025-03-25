module SCPU_TOP(
    input clk,                  // 时钟信号
    input rstn,                 // 复位信号，低电平有效
    input [15:0] sw_i,          // 开关输入，用于调试和测试
    output [7:0] disp_an_o,     // 数码管选择
    output [7:0] disp_seg_o     // 数码管段码
);
    reg [31:0] clkdiv;
    wire Clk_CPU;
    always @(posedge clk or negedge rstn) begin
        if (!rstn)
            clkdiv <= 0;
        else
            clkdiv <= clkdiv + 1'b1;
    end
    assign Clk_CPU = (sw_i[15]) ? clkdiv[27] : clkdiv[25]; // 控制时钟频率
    wire [31:0] rom_addr;       // 当前指令地址
    wire [31:0] instr;          // 指令
    wire [6:0] Op = instr[6:0]; // 操作码
    wire [6:0] Funct7 = instr[31:25]; // 功能字段7位
    wire [2:0] Funct3 = instr[14:12]; // 功能字段3位
    wire [31:0] NPC;            // 下一指令地址
    wire [2:0] NPCOp;           // NPC 操作控制信号
    wire RegWrite;              // 寄存器写使能
    wire MemWrite;              // 内存写使能
    wire [4:0] ALUOp;           // ALU 操作信号
    wire ALUSrc;                // ALU 第二操作数来源
    wire Zero;                  // Zero 标志
    wire [31:0] aluout;         // ALU 运算结果
    wire [31:0] RD1, RD2;       // 寄存器文件的读出数据
    wire [31:0] WD;             // 寄存器写入数据
    wire [31:0] immout;         // 立即数扩展输出
    // 实例化 PC 模块
    PC U_PC(
        .clk(Clk_CPU),
        .rstn(rstn),
        .sw_i(sw_i),
        .PC(rom_addr),
        .NPC(NPC),
        .PCout(rom_addr)
    );

    // 实例化 NPC 模块
    NPC U_NPC(
        .PC(rom_addr),
        .NPCOp(NPCOp),
        .immout(immout),
        .aluout(aluout),
        .NPC(NPC)
    );

    // 实例化指令存储器
    dist_mem_gen_im U_IM(
        .a(rom_addr[10:2]), // 地址位宽调整，支持跳转指令
        .spo(instr)         // 输出指令
    );

    // 实例化控制模块
    ctrl U_Ctrl(
        .Op(Op),
        .Funct7(Funct7),
        .Funct3(Funct3),
        .Zero(Zero),
        .RegWrite(RegWrite),
        .MemWrite(MemWrite),
        .ALUSrc(ALUSrc),
        .ALUOp(ALUOp),
        .NPCOp(NPCOp)
    );

    // 实例化寄存器文件
    RF U_RF(
        .clk(Clk_CPU),
        .rstn(rstn),
        .RFWr(RegWrite),
        .A1(instr[19:15]), // rs1
        .A2(instr[24:20]), // rs2
        .A3(instr[11:7]),  // rd
        .WD(WD),           // 写入数据
        .RD1(RD1),         // 读数据1
        .RD2(RD2)          // 读数据2
    );

    // ALU
    alu U_ALU(
        .A(RD1),
        .B(ALUSrc ? immout : RD2),
        .ALUOp(ALUOp),
        .C(aluout),
        .Zero(Zero)
    );

    // 数据写回选择
    assign WD = (NPCOp[2]) ? rom_addr + 4 : // PC 写回
                (ALUSrc)  ? aluout : RD2;  // ALU 或数据存储器写回

    // 数码管显示模块
    seg7x16 u_seg7x16(
        .clk(clk),
        .rstn(rstn),
        .i_data(aluout),  // 显示 ALU 结果
        .disp_mode(sw_i[0]),
        .o_seg(disp_seg_o),
        .o_sel(disp_an_o)
    );

endmodule