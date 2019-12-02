let values =
  Node.Fs.readFileAsUtf8Sync("../data/day_01_1.txt")
  |> Js.String.split("\n")
  |> Belt.Array.map(_, Js.Float.fromString);

let rec calcFuel = w => {
  let fuel = w / 3 - 2;
  if (fuel < 1) {
    0;
  } else {
    fuel + calcFuel(fuel);
  };
};

let lineReducer = (acc, value) => {
  acc + calcFuel(int_of_float(value));
};

let finalResult = Belt.Array.reduce(values, 0, lineReducer);

Js.log(finalResult);
