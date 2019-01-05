# filter:

## averaging filter

1(1 1 1)
-(1 1 1)
9(1 1 1)

## Gaussian filter

G(x, y, σ) = ( 1/2piσ^2 ) exp(-(x^2 + y^2)/2σ^2)

## bilateral filter

I~(x, y) = (Σi=-N N)(Σj=-N N)W(x,y,i,j)I(x+i,y+j)/(Σi=-N N)(Σj=-N N)W(x,y,i,j)

W(x,y,i,j) = exp(-(((x-i)^2+(y-j)^2)/2σ^2) - (||I(x,y)-I(i,j)||/2σ^2))
