f = @(x) (x.* tan(x)) - 3
fDer = @(x) tan(x) + (x .* sec(x).^2)
x=0:0.01:8;
plot(x,f(x))
hold on

p0 = 5;
p1 = 8;
q0 = f(p0);
q1 = f(p1);


epsilon = 10^-6;

#secant green
[p,iter] = func_secant(p0,p1,q0,q1,epsilon);
fprintf("c=%d, f(c)=%d, iteration =%d \n",p,f(p),iter); 
plot(p,f(p),'g+')

#regular falsi black
[p,iter] = func_falsi(p0,p1,q0,q1,epsilon);
fprintf("c=%d, f(c)=%d, iteration =%d \n",p,f(p),iter); 
plot(p,f(p),'b+')

#?newton red
[p,iter] = func_newton(f, fDer, p0, epsilon);
fprintf("c=%d, f(c)=%d, iteration =%d \n",p,f(p),iter); 
plot(p,f(p),'r+')