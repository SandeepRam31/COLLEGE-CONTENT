module not1 (input wire a, output wire y);
assign y =! a;
endmodule

module and1(input wire a, b, c, output wire y);
assign y = a&b&c;
endmodule


module demux(input wire a,b,c, output wire s0, s1, s2, s3);
wire t,t1;
not1 a1(b,t);
not1 a2(c,t1);
and1 a3(a, b, c, s0);
and1 a4(a, b, t1, s1);
and1 a5(a, t, c, s2);
and1 a6(a, t, t1, s3);
endmodule
