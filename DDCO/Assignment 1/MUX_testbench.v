module tb;
reg a,b,c,d,s_0, s_1;
wire y;
mux2 a1(.a(a),.b(b),.c(c),.d(d),.s_0(s_0),.s_1(s_1),.y(y));

initial begin 
$dumpfile("abc.vcd");
$dumpvars(0,tb);
end

initial begin 
$monitor (a,b,c,d,s_1, s_0, y);

a=1'b0;
b=1'b1;
c=1'b0;
d=1'b1;
s_0=1'b0;
s_1=1'b0;
#10

a=1'b1;
b=1'b0;
c=1'b1;
d=1'b0;
s_0=1'b0;
s_1=1'b1;
#10
a=1'b0;
b=1'b0;
c=1'b1;
d=1'b0;
s_0=1'b1;
s_1=1'b0;
#10
a=1'b0;
b=1'b0;
c=1'b1;
d=1'b0;
s_0=1'b1;
s_1=1'b1;
#10
a=1'b0;
b=1'b0;
c=1'b0;
d=1'b0;
s_0=1'b1;
s_1=1'b1;
end
endmodule