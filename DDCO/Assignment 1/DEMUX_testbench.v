module tb;
reg a,b,c;
wire s0, s1, s2, s3;
demux a1(.a(a), .b(b),.c(c), .s0(s0), .s1(s1), .s2(s2), .s3(s3));


initial begin 
$dumpfile("abc.vcd");
$dumpvars(0,tb);
end

initial begin 
$monitor (a,b, c, s0, s1, s2, s3);

a=1'b0;
b=1'b0;
c=1'b0;
#10
a=1'b1;
b=1'b0;
c=1'b0;
#10
a=1'b0;
b=1'b1;
c=1'b1;
#10
a=1'b1;
b=1'b1;
c=1'b1;
#10
a=1'b0;
b=1'b1;
c=1'b0;
end
endmodule