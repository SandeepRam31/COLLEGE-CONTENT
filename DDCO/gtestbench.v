module tb;
reg t_a;
wire t_c;
//instantiate

not1 a1(.a(t_a));
initial begin $dumpfile("dump.vcd");
$dumpvars(0,tb);
end

initial begin $monitor(t_a);
t_a=1'b0; //1 bit input
#10 //time nanosecs

t_a=1'b1;
#10

end

endmodule

