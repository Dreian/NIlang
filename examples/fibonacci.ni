var x : integer;
    y : integer;
    z : integer;
    n : integer;
    b : boolean;

begin
  x := 0;
  y := 1;
  z := 0;
  n := 20;
  while n > 0 do begin
    n := n - 1;
    z := x + y;
    x := y;
    y := z
  end;
  print(z)
end.