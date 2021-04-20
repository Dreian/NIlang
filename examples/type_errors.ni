var x : integer;
    y : boolean;
    z : boolean;
    x : boolean;

begin
  x := false;
  z := true;
  y := x > 0 and z;
  if x then begin
    z := 2 + 3
  end;
  while x <> false do
    y := z + y
end.
