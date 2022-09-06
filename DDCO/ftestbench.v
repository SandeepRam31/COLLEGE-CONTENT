module tb;
reg t_a;
reg t_b;
wire t_c;
//instantiate

xnor1 a1(.a(t_a),.b(t_b));
initial begin $dumpfile("dump.vcd");
$dumpvars(0,tb);
end

initial begin $monitor(t_a,t_b);
t_a=1'b0; //1 bit input
t_b=1'b0;
#10 //time nanosecs

t_a=1'b0;  //1 bit input
t_b=1'b1;
#10 

t_a=1'b1;
t_b=1'b0;
#10

t_a=1'b1;
t_b=1'b1;

end

endmodule

