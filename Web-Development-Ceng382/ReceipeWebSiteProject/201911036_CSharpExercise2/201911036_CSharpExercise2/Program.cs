using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _201911036_CSharpExercise2
{
    class Recipe
    {
        public string name { get; set; }
        public string type { get; set; }
        public string cuisine { get; set; }
        public bool vegeterian { get; set; }
        public string ingredient { get; set; }

        public string directions { get; set; }

        public void Create(string name, string type, string cuisine, bool vegeterian, string ingredient, string directions)
        {
            this.name = name;
            this.type = type;
            this.cuisine = cuisine;
            this.vegeterian = vegeterian;
            this.ingredient = ingredient;
            this.directions = directions;
        }

        public void Read()
        {
            if (vegeterian)
                Console.WriteLine("{0} \n Cuisine: {1} \n Vegeterian: Yes \n Ingredients {2} \n Directions {3} \n \n", name, cuisine, ingredient, directions);
            else
                Console.WriteLine("{0} \n Cuisine: {1} \n Vegeterian: No \n Ingredients {2} \n Directions {3} name, type, ingredient, directions \n \n", name, cuisine, ingredient, directions);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<Recipe> recipes = new List<Recipe>();
            Recipe recipe1 = new Recipe();
            recipe1.Create("Spicy Lentil Soup", "Vegeterian", "Turkish", true, "red lentils, onions, tomatoes, garlic, olive oil, spices", "Boil lentils until tender, saute onions and garlic in olive oil, add diced tomatoes and spices,add cooked lentils and simmer for 20 minutes");

            Recipe recipe2 = new Recipe();
            recipe2.Create("Eggplant and Tomato Casserole", "Vegeterian", "Turkish", true, "eggplant, tomatoes, onions, garlic, olive oil, herbs, cheese (optional)", "Slice eggplant and tomatoes, saute onions and garlic in olive oil, layer eggplant and tomatoes in a baking dish with herbs and optional cheese, bake at 375 degrees for 45 minutes");

            Recipe recipe3 = new Recipe();
            recipe3.Create("Boiled Egg", "Normal", "International", false, "egg, water", "Place eggs in a pot with cold water. Bring water to boil. Turn off heat and cover pot, letting eggs sit for 9-12 minutes. Remove eggs from hot water and place in cold water.Once cool, peel the shell off the eggs.");

            Recipe recipe4 = new Recipe();
            recipe4.Create("Stuffed Grape Leaves", "Vegeterian", "Turkish", true, "grape leaves, rice, onions, tomatoes, parsley, olive oil, lemon juice, spices", "Rinse grape leaves and blanch in boiling water, saute onions and garlic in olive oil, add diced tomatoes and rice, mix in parsley and spices, wrap mixture in grape leaves and steam for 30 minutes");

            recipes.Add(recipe1);
            recipes.Add(recipe2);
            recipes.Add(recipe3);
            recipes.Add(recipe4);

            Console.WriteLine("Welcome to the Recipe Finder app! \n \n");
            Console.WriteLine(" I.E - Try with Vegeterian for first input Turkish for second input \n");
            Console.WriteLine("Please enter the type of recipe you're looking for (Please start with caiptal letter)(e.g. vegetarian, vegan, gluten-free):");
            string type = Console.ReadLine();
            Console.WriteLine("\n Please enter the cuisine you're interested in (Please start with caiptal letter)(e.g. Italian, Mexican, Chinese): ");
            string cuisine = Console.ReadLine();
            Console.WriteLine("\n \n Here are the {0} {1} recipes we found: ", type, cuisine);

            foreach (var variable in recipes)
            {
                if (variable.cuisine == cuisine && variable.type == type)
                {
                    variable.Read();
                }
            }
        }
    }
}
