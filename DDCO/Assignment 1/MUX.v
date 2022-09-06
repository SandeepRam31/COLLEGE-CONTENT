module not1 (input wire a, output wire y);
assign y =! a;
endmodule

module and1(input wire a, b, output wire y);
assign y = a&b;
endmodule

module or1(input wire a,b,output wire y);
assign y = a|b;
endmodule

module mux(input wire a,b,c,output wire y);
wire t,t1,t2;
not1 a1(a,t);
and1 a2(t,b,t1);
and1 a3(a,c,t2);
or1 a4(t1,t2,y);
endmodule

module mux2(input a,b,c,d,s_0,s_1,output wire y);
wire t,t1, g;
mux m1(s_0,a,b,t);
mux m2(s_0,c,d,t1);
mux o1(s_1,t,t1,y);
endmodule