var
  n : integer;
  s : integer;
begin
  n := 1000;
  s := 0;
  while n > 0 do begin
    s := s + n;
    n := n - 1
  end;
  print(s)
end.
