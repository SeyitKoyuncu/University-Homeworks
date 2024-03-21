figure
x=1:0.0001:3;
plot(x,func(x))
hold on


%a=1;
%b=3;
a=x(1);
b=x(length(x));
c=(a+b)/2;
epsilon=10^-5
while (abs(func(c))>epsilon)
  if(func(c)*func(a))<0
    b=c;
  else
    a=c;
  end

plot(c,func(c),'ro');
fprintf("c=%d, f(c)=%d, (%d,%d )\n",c,func(c),a,b); 
  c=(a+b)/2;
  pause(4)
end

plot(c,func(c),'g+');
