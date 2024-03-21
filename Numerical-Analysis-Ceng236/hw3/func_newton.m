function [p0,iter]=func_newton(f, fDer, p0, epsilon)
  iter = 0
  while(iter < 100)
    d = f(p0) / fDer(p0)
    p0 = p0 - d
    if(abs(d) < epsilon)
      fprintf('\nApproximate solution xn= %11.8f \n\n',p0);
      break;
      
    else
       iter = iter + 1;
    end
  end