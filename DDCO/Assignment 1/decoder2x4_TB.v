module tb;
reg t_s0, t_s1;
wire t_a, t_b, t_c, t_d;

decoder2x4 a1(.s0(t_s0), .s1(t_s1), .a(t_a), .b(t_b), .c(t_c), .d(t_d));

initial begin
$dumpfile("abc.vcd");
$dumpvars(0,tb);
end

initial begin
$monitor(t_s0, t_s1, t_a, t_b, t_c, t_d);

t_s0 = 1'b0 ;
t_s1 = 1'b0 ;
#10

t_s0 = 1'b0 ;
t_s1 = 1'b1 ;
#10

t_s0 = 1'b1 ;
t_s1 = 1'b0 ;
#10

t_s0 = 1'b1 ;
t_s1 = 1'b1 ;
#10

t_s0 = 1'b0 ;
t_s1 = 1'b0 ;
end
endmodule


