module ctrl(
    input [6:0] Op,
    input [6:0] Funct7,
    input [2:0] Funct3,
    input Zero,
    output RegWrite,
    output MemWrite,
    output [5:0] EXTOp,
    output [2:0] NPCOp,
    output [4:0] ALUOp,
    output ALUSrc,
    output [2:0] DMType,
    output [1:0] WDSel
);

    // 指令类型解析
    wire rtype = (Op == 7'b0110011);
    wire itype_l = (Op == 7'b0000011);
    wire itype_r = (Op == 7'b0010011);
    wire stype = (Op == 7'b0100011);
    wire sbtype = (Op == 7'b1100011);
    wire i_jal = (Op == 7'b1101111);
    wire i_jalr = (Op == 7'b1100111) & (Funct3 == 3'b000);

    // 条件分支指令
    wire i_beq = sbtype & (Funct3 == 3'b000);
    wire i_bne = sbtype & (Funct3 == 3'b001);
    wire i_blt = sbtype & (Funct3 == 3'b100);
    wire i_bge = sbtype & (Funct3 == 3'b101);
    wire i_bltu = sbtype & (Funct3 == 3'b110);
    wire i_bgeu = sbtype & (Funct3 == 3'b111);

    // 位移指令
    wire i_sll = rtype & (Funct3 == 3'b001) & (Funct7 == 7'b0000000);
    wire i_srl = rtype & (Funct3 == 3'b101) & (Funct7 == 7'b0000000);
    wire i_sra = rtype & (Funct3 == 3'b101) & (Funct7 == 7'b0100000);

    // 控制信号生成
    assign RegWrite = rtype | itype_r | itype_l | i_jal | i_jalr;
    assign MemWrite = stype;
    assign ALUSrc = itype_r | stype | itype_l | i_jalr;

    assign NPCOp = {i_jalr, i_jal, (sbtype & Zero)};
    assign WDSel = {i_jal | i_jalr, itype_l};

    assign ALUOp[0] = i_add | i_addi | stype | i_sll | i_srl | i_sra;
    assign ALUOp[1] = i_add | i_addi | i_slt | i_slti | i_sll | i_sra;
    assign ALUOp[2] = i_slt | i_blt | i_srl | i_sra;
    assign ALUOp[3] = i_slt;
    assign ALUOp[4] = i_slti;

    assign EXTOp = {i_jalr, i_jal, sbtype, stype, itype_l | itype_r};

    assign DMType = (itype_l & Funct3 == 3'b100) ? 3'b100 : 3'b000;

endmodule
