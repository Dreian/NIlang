var x : integer;
    y : integer;
    tmp : integer;
    mod : integer;

begin
  x := 156;
  y := 455;
  if y > x then begin
    tmp := x;
    x := y;
    y := tmp
  end;
  while y > 0 do begin
    mod := x - y * (x div y);
    x := y;
    y := mod
  end;
  print(x)
end.
