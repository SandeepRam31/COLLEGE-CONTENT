module not1 (input wire a, output wire y);
assign y =! a;
endmodule

module and1(input wire a, b, output wire y);
assign y = a&b;
endmodule

module or1(input wire a,b,output wire y);
assign y = a|b;
endmodule

module decoder2x4(input wire s0,s1,output wire a,b,c,d);
wire t1,t2 ;

not1 a1(s0,t1);
not1 a2(s1,t2);
and1 a3(t1,t2,a);
and1 a4(t1,s1,b);
and1 a5(s0,t2,c);
and1 a6(s0,s1,d);

endmodule
