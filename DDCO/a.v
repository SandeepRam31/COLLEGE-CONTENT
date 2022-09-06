module and1(a,b);
input a,b;
output c;
assign c=a&b;  //and
endmodule

module or1(a,b);
input a,b;
output c;
assign c=a|b;  //or
endmodule

module not1(a,b);
input a;
output c;
assign c=!a;  //not
endmodule

module nand1(a,b);
input a,b;
output c;
assign c=!(a&b);  //nand
endmodule

module nor1(a,b);
input a,b;
output c;
assign c=!(a|b);  //nor
endmodule

module xor1(a,b);
input a,b;
output c;
assign c=a^b;  //xor
endmodule

module xnor1(a,b);
input a,b;
output c;
assign c=!(a^b);  //xnor
endmodule