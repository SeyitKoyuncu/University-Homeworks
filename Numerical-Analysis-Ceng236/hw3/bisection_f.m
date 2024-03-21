function [c,iter]=bisection_f(f, a,b, epsilon)

c = (a+b)/2;

iter = 0;
fprintf("Bisection Method");
while (abs(f(c))>epsilon)
  if(f(c)*f(a))<0
    b=c;
  else
    a=c;
  end
iter = iter+1;
#plot(c,myfun2(c),'ro');
fprintf("c=%d, f(c)=%d, (%d,%d )\n",c,f(c),a,b); 
  c=(a+b)/2;
 # pause(4)
end

#plot(c,myfun2(c),'g+');
