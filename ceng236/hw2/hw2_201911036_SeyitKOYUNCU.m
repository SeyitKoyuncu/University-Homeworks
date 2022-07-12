figure
x=0:0.0001:3;
plot(x,func(x))
hold on

i = 2
p0 = 2
p1 = 15
q0 = func(p0)
q1 = func(p1)

epsilon = 10^-30
while i < 15
  p = p1 - q1*(p1-p0)/(q1-q0)
  if(abs(p-p1) < epsilon)
    printf("result is = %d",p)
  end
  plot(p,func(p),'ro');
  pause(4)
  i = i + 1
  q = func(p)
  if(q * q1 < 0)
    p0 = p1
    q0 = q1
  end
  p1 = p
  q1 = q    
end

plot(p,func(p),'g+');
display("Method failed after 15 iteration")