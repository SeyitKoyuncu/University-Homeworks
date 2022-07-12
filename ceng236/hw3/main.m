f = @(x) x.^2+4*x -4;
x = -4:0.01:5 ;
plot(x,f(x))
hold on
a = x(1);
b = x(length(x));
c = (a+b)/2;
epsilon = 10^-5;
[c,iter] = bisection_f(f, a, b, epsilon);
fprintf("c=%d, f(c)=%d, iteration =%d \n",c,f(c),iter); 
plot(c,f(c),'g+')