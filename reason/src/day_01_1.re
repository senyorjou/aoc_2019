let values =
  Node.Fs.readFileAsUtf8Sync("../data/day_01_1.txt") |> Js.String.split("\n");

let lineReducer = (acc, value) => {
  let value = Js.Float.fromString(value);

  switch (value) {
  | 0.0 => acc
  | _ => acc + int_of_float(value) / 3 - 2
  };
};

let finalResult = Belt.Array.reduce(values, 0, lineReducer);

Js.log(finalResult);
