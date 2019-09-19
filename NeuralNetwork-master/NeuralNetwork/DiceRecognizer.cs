using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeuralNetwork
{
    class DiceRecognizer
    {
        public static void Run(int epochsCount, int hiddenLayerNeuronsCount, Function func, string trainFilename, string validFilename)
        {

            List<string> notes = new List<string>();

            Console.WriteLine("Creating neural network...");

            var network = new NeuralNetwork(4356, hiddenLayerNeuronsCount, 10, 0.3);

            var dataset = File.ReadAllLines(trainFilename);

            var allInputs = dataset
                .Select(x => x.Split(new[] { ',' }, StringSplitOptions.RemoveEmptyEntries)).ToArray();

            Console.WriteLine($"Training network with {allInputs.Length} samples...");

            var normalizedInputs = allInputs.Select(x => new
            {
                Answer = x[0][1].ToString(),
                Inputs = NormalizeInput(x.Skip(1).ToArray())
            }).ToArray();

            for (int k = 0; k < epochsCount; k++)
            {

                var s = new Stopwatch();
                s.Start();

                int i = 0;

                switch (func)
                {
                    case Function.Sigmoid:
                        foreach (var input in normalizedInputs)
                        {
                            var targets = Enumerable.Range(0, 10).Select(x => 0.0).Select(x => x + 0.01).ToArray();
                            targets[int.Parse(input.Answer)] = 0.99;

                            network.TrainUsingSigmoid(input.Inputs, targets);
                        }
                        break;
                    case Function.Sinus:
                        foreach (var input in normalizedInputs)
                        {
                            var targets = Enumerable.Range(0, 10).Select(x => 0.0).Select(x => x + 0.01).ToArray();
                            targets[int.Parse(input.Answer)] = 0.99;

                            network.TrainUsingSinus(input.Inputs, targets);
                        }
                        break;
                    case Function.SquareRoot:
                        foreach (var input in normalizedInputs)
                        {
                            var targets = Enumerable.Range(0, 10).Select(x => 0.0).Select(x => x + 0.01).ToArray();
                            targets[int.Parse(input.Answer)] = 0.99;

                            network.TrainUsingRoot(input.Inputs, targets);
                        }
                        break;

                }


                s.Stop();
                Console.WriteLine($"Epoch: {k+1}");
                Console.WriteLine($"Training complete in {s.ElapsedMilliseconds}ms{Environment.NewLine}");
                Console.WriteLine("Querying network...");

                var queryDataset = File.ReadAllLines(validFilename); ;

                var queryInputs = queryDataset
                    .Select(x => x.Split(new[] { ',' }, StringSplitOptions.RemoveEmptyEntries)).ToArray();

                var scoreCard = new List<bool>();


                switch (func)
                {
                    case Function.Sigmoid:
                        foreach (var input in queryInputs)
                        {
                            var normalizedInput = NormalizeInput(input.Skip(1).ToArray());
                            var correctAnswer = int.Parse(input[0][1].ToString());
                            var response = network.QueryUsingSigmoid(normalizedInput);

                            var max = response.Max(x => x);
                            var f = response.ToList().IndexOf(max);

                            scoreCard.Add(correctAnswer == f);
                        }
                        break;
                    case Function.Sinus:
                        foreach (var input in queryInputs)
                        {
                            var normalizedInput = NormalizeInput(input.Skip(1).ToArray());
                            var correctAnswer = int.Parse(input[0][1].ToString());
                            var response = network.QueryUsingSinus(normalizedInput);

                            var max = response.Max(x => x);
                            var f = response.ToList().IndexOf(max);

                            scoreCard.Add(correctAnswer == f);
                        }
                        break;
                    case Function.SquareRoot:
                        foreach (var input in queryInputs)
                        {
                            var normalizedInput = NormalizeInput(input.Skip(1).ToArray());
                            var correctAnswer = int.Parse(input[0][1].ToString());
                            var response = network.QueryUsingRoot(normalizedInput);

                            var max = response.Max(x => x);
                            var f = response.ToList().IndexOf(max);

                            scoreCard.Add(correctAnswer == f);
                        }
                        break;

                }


                Console.WriteLine($"Performed {scoreCard.Count} queries. Correct answers were {scoreCard.Count(x => x)}.");
                Console.WriteLine($"Network has a performance of {scoreCard.Count(x => x) / Convert.ToDouble(scoreCard.Count)}");
                string note = $"{scoreCard.Count(x => x) / Convert.ToDouble(scoreCard.Count)}";
                notes.Add(note);
            }
            using (StreamWriter sw = new StreamWriter($"out/Epochs{epochsCount}HiddenLayerNeuronsCount{hiddenLayerNeuronsCount}Function{func}UsingFile{trainFilename}.txt"))
            {
                foreach (var str in notes)
                {
                    sw.WriteLine(str);

                }
            }
            Console.Clear();
        }

        private static double[] NormalizeInput(string[] input)
        {
            double[] doubles = new double[input.Length];
            for (int i = 0; i < input.Length - 1; i++)
            {
                doubles[i] = Double.Parse(input[i]);
            }
            doubles[input.Length - 1] = 0;
            return doubles;
        }
    }
}