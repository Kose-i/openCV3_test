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

## Prewitt filter

     (-1 0 1)
Fx = (-1 0 1)
     (-1 0 1)

     (-1 -1 -1)
Fy = ( 0  0  0)
     ( 1  1  1)

## Sobel filter

     (-1 0 1)
Fx = (-2 0 2)
     (-1 0 1)

     (-1 -2 -1)
Fy = ( 0  0  0)
     ( 1  2  1)

## Laplacian of Gaussian filter
