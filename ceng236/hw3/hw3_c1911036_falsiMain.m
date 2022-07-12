f = @(x) (x.* tan(x)) - 3
x=0:0.01:10;
plot(x,f(x))
hold on

p0 = 5;
p1 = 8;
q0 = f(p0);
q1 = f(p1);

epsilon = 10^-6;
[p,iter] = func_falsi(p0,p1,q0,q1,epsilon);
fprintf("c=%d, f(c)=%d, iteration =%d \n",p,f(p),iter); 
plot(p,f(p),'y+')