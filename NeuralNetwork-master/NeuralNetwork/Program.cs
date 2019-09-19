using System;

namespace NeuralNetwork
{
    class Program
    {
        static void Main(string[] args)
        {
            DiceRecognizer.Run(20, 8, Function.Sigmoid, "train.csv", "valid.csv");
            DiceRecognizer.Run(20, 64, Function.Sigmoid, "train.csv", "valid.csv");
            DiceRecognizer.Run(10, 128, Function.Sigmoid, "train.csv", "valid.csv");
            DiceRecognizer.Run(10, 256, Function.Sigmoid, "train.csv", "valid.csv");
            DiceRecognizer.Run(10, 512, Function.Sigmoid, "train.csv", "valid.csv");
            DiceRecognizer.Run(10, 1024, Function.Sigmoid, "train.csv", "valid.csv");

            DiceRecognizer.Run(20, 8, Function.Sinus, "train.csv", "valid.csv");
            DiceRecognizer.Run(20, 64, Function.Sinus, "train.csv", "valid.csv");
            DiceRecognizer.Run(10, 128, Function.Sinus, "train.csv", "valid.csv");
            DiceRecognizer.Run(10, 256, Function.Sinus, "train.csv", "valid.csv");
            DiceRecognizer.Run(10, 512, Function.Sinus, "train.csv", "valid.csv");
            DiceRecognizer.Run(10, 1024, Function.Sinus, "train.csv", "valid.csv");

            DiceRecognizer.Run(20, 8, Function.SquareRoot, "train.csv", "valid.csv");
            DiceRecognizer.Run(20, 64, Function.SquareRoot, "train.csv", "valid.csv");
            DiceRecognizer.Run(10, 128, Function.SquareRoot, "train.csv", "valid.csv");
            DiceRecognizer.Run(10, 256, Function.SquareRoot, "train.csv", "valid.csv");
            DiceRecognizer.Run(10, 512, Function.SquareRoot, "train.csv", "valid.csv");
            DiceRecognizer.Run(10, 1024, Function.SquareRoot, "train.csv", "valid.csv");

            DiceRecognizer.Run(20, 8, Function.Sigmoid, "train2.csv", "valid.csv");
            DiceRecognizer.Run(20, 64, Function.Sigmoid, "train2.csv", "valid.csv");
            DiceRecognizer.Run(10, 128, Function.Sigmoid, "train2.csv", "valid.csv");
            DiceRecognizer.Run(10, 256, Function.Sigmoid, "train2.csv", "valid.csv");
            DiceRecognizer.Run(10, 512, Function.Sigmoid, "train2.csv", "valid.csv");
            DiceRecognizer.Run(10, 1024, Function.Sigmoid, "train2.csv", "valid.csv");

            DiceRecognizer.Run(20, 8, Function.Sigmoid, "train3.csv", "valid.csv");
            DiceRecognizer.Run(20, 64, Function.Sigmoid, "train3.csv", "valid.csv");
            DiceRecognizer.Run(10, 128, Function.Sigmoid, "train3.csv", "valid.csv");
            DiceRecognizer.Run(10, 256, Function.Sigmoid, "train3.csv", "valid.csv");
            DiceRecognizer.Run(10, 512, Function.Sigmoid, "train3.csv", "valid.csv");
            DiceRecognizer.Run(10, 1024, Function.Sigmoid, "train3.csv", "valid.csv");
        }
    }
}
