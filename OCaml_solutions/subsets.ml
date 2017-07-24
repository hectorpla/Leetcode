let rec subsets lst =
match lst with
| [] -> [[]]
| _ -> let after = subsets (List.tl lst) in
(List.map (fun acc -> (List.hd lst) :: acc) after) @ after;;
