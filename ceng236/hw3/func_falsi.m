function [p,iter]=func_falsi(p0,p1,q0,q1,epsilon)
  f = @(x) (x.* tan(x)) - 3
  iter = 0;
  while iter < 100
  p = p1 - (q1*((p1-p0)/(q1-q0)))
  if(abs(p-p1) < epsilon)
    printf("result is = %d",p)
    printf("\n p - p1 is = %d",abs(p-p1))
    break;
  end

  q = f(p)
  iter = iter + 1;
  if(q * q1 > 0)
    p0 = p1
    q0 = q1
  end
  p1 = p
  q1 = q    
end