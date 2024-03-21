using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace _201911036_CSharpExercise1
{
    class Recipe
    {
        private int ID = 0;
        public string title { get; set; }
        public string description { get; set; }
        public string cuisine { get; set; }
        public int difficultyLevel { get; set; }
        public int preparationTime { get; set; }
        public int cookingTime { get; set; }
        public int servings { get; set; }
        public int authorID { get; set; }
        public List<Ingredient> ingredients = new List<Ingredient>();

        public int getID() { return ID; }
        public void Create(string name, string description, string cuisine, int id)
        {
            ID = id;
            this.title = name;
            this.description = description;
            this.cuisine = cuisine;
        }

        public void Update(string name, string description, string cuisine, List<Recipe> receipes, int index)
        {
            this.title = name;
            receipes[index].title = name;

            this.cuisine = cuisine;
            receipes[index].cuisine = cuisine;

            this.description = description;
            receipes[index].description = description;
        }
        public void Read()
        {
            Console.WriteLine("ID = {0}, Name = {1}, Cuisine = {2}. Description = {3}.", ID, title, cuisine, description);
        }

        public void AddIngredient(Ingredient ingredient)
        {
            ingredients.Add(ingredient);
        }
        public void Delete(List<Recipe> receipes, int id)
        {
            int index = -1;
            int count = 0;
            foreach (var value in receipes)
            {
                if (value.ID == id)
                    index = count;
                count++;
            }
            if (index == -1)
            {
                Console.WriteLine("This id can not be found");
                return;
            }

            else
            {
                receipes.RemoveAt(index);
            }
        }
    }

    class Ingredient
    {
        private int ID = 0;
        public string name { get; set; }
        public string unit { get; set; }
        public int quantitiy { get; set; }
        private int receipeID { get; set; }
        public string description { get; set; }

        public int getID() { return ID; }
        public void Create(string name, string description, int calorie, int id)
        {
            ID = id;
            this.name = name;
            this.description = description;
            quantitiy = calorie;
        }
        public void Update(string name, int calorie, string description, List<Ingredient> ingredients, int index)
        {

            this.name = name;
            ingredients[index].name = name;

            this.description = description;
            ingredients[index].description = description;

            this.quantitiy = calorie;
            ingredients[index].quantitiy = calorie;
        }

        public void Read()
        {
            Console.WriteLine("ID = {0}, Name = {1}, Calorie = {2}. Description = {3}.", ID, name, quantitiy, description);
        }

        public void Delete(List<Ingredient> Ingredients, int id)
        {
            int index = -1;
            int count = 0;
            foreach (var value in Ingredients)
            {
                if (value.ID == id)
                    index = count;
                count++;
            }
            if (index == -1)
            {
                Console.WriteLine("This id can not be found");
                return;
            }

            else
            {
                Ingredients.RemoveAt(index);
            }
        }
    }

    class Rating
    {
        private int ID = 0;
        public double value { get; set; }
        private int receipeID { get; set; }
        public int getID() { return ID; }

        public void Create(double value, int id)
        {
            ID = id;
            this.value = value;
        }
        public void Update(double value, List<Rating> ratings, int id)
        {
            this.value = value;
            ratings[id].value = value;
        }

        public void Read()
        {
            Console.WriteLine("ID = {0}, Value = {1}.", ID, value);
        }

        public void Delete(List<Rating> Ratings, int id)
        {
            int index = -1;
            int count = 0;
            foreach (var value in Ratings)
            {
                if (value.ID == id)
                    index = count;
                count++;
            }
            if (index == -1)
            {
                Console.WriteLine("This id can not be found");
                return;
            }

            else
            {
                Ratings.RemoveAt(index);
            }
        }
    }

    class Program
    {
        void MainMenu()
        {
            Console.WriteLine("What would you like to do ? \n" +
                              " 1. Manage recipes \n " +
                              "2. Manage ingredients \n " +
                              "3. Manage Ratings \n " +
                              "4. Exit \n \n " +
                              "Please enter a number: ");

        }

        void ReceipeMenu()
        {
            Console.WriteLine("What would you like to do with recipes? \n " +
                              "1. Wiev all recipes \n " +
                              "2. Add recipe \n " +
                              "3. Update receipe \n " +
                              "4. Delete a recipe \n " +
                              "5. Return to main menu \n \n" +
                              "Please enter a number");
        }

        void IngredientMenu()
        {
            Console.WriteLine("What would you like to do with ingredients? \n " +
                              "1. Wiev all ingredients \n " +
                              "2. Add ingredients \n " +
                              "3. Update ingredients \n " +
                              "4. Delete a ingredients \n " +
                              "5. Return to main menu \n \n" +
                              "Please enter a number");
        }

        void RatingMenu()
        {
            Console.WriteLine("What would you like to do with ratings? \n " +
                              "1. Wiev all ratings \n " +
                              "2. Add ratings \n " +
                              "3. Update ratings \n " +
                              "4. Delete a ratings \n " +
                              "5. Return to main menu \n \n" +
                              "Please enter a number");
        }

        static void Main(string[] args)
        {
            Program main = new Program();
            int choice = -1;

            int recipeCount = 1;
            int ingredientCount = 1;
            int ratingCount = 1;

            var recipes = new List<Recipe>();
            var ratings = new List<Rating>();
            var ingredients = new List<Ingredient>();

            Console.Write("Welcome to the Recipe Manager! \n \n");


            while (choice != 4)
            {
                main.MainMenu();
                choice = Convert.ToInt32(Console.ReadLine());

                if (choice == 1)
                {
                    main.ReceipeMenu();
                    int recipeMenuChoice = Convert.ToInt32(Console.ReadLine());

                    if (recipeMenuChoice == 1)
                    {
                        if (recipes.Capacity <= 0)
                            Console.WriteLine("No recipes found. \n");
                        else
                        {
                            Console.WriteLine("Here are all the recipies \n");
                            foreach (var recipe in recipes)
                                recipe.Read();
                        }
                    }

                    else if (recipeMenuChoice == 2)
                    {
                        Console.WriteLine("Please enter the recipe name: ");
                        string recipeName = Console.ReadLine();
                        Console.WriteLine("\n Please enter the recipe cuisine: ");
                        string recipeCuisine = Console.ReadLine();
                        Console.WriteLine("\n Please enter the recipe description: ");
                        string recipeDescription = Console.ReadLine();
                        Console.WriteLine("\n \n Great! Recipe added succesfully. ");
                        Recipe recipe = new Recipe();
                        recipe.Create(recipeName, recipeDescription, recipeCuisine, recipeCount);
                        recipes.Add(recipe);
                        recipeCount++;
                    }

                    else if (recipeMenuChoice == 3)
                    {
                        Console.WriteLine("\n Please enter the ID of the recipe you want to update: ");
                        int updateRecipeID = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine("\n Please enter the new recipe name(or press entr to skip): ");
                        string newRecipeName = Console.ReadLine();
                        Console.WriteLine("\n Please enter the new recie cuisine(or press enter to skip): ");
                        string newRecipeCuisine = Console.ReadLine();
                        Console.WriteLine("\n Please enter the new recipe description(or press enter to skip): ");
                        string newRecipeDescription = Console.ReadLine();
                        int index = -1;
                        int count = 0;
                        foreach (var value in recipes)
                        {
                            if (value.getID() == updateRecipeID)
                                index = count;
                            count++;
                        }
                        if (index == -1)
                            Console.WriteLine("This id can not be found");
                        else
                            recipes[index].Update(newRecipeName, newRecipeDescription, newRecipeCuisine, recipes, index);
                    }

                    else if (recipeMenuChoice == 4)
                    {
                        Console.WriteLine("\n Please enter the ID of the recipe you want to delete: ");
                        int deleteID = Convert.ToInt32(Console.ReadLine());
                        recipes[deleteID - 1].Delete(recipes, deleteID);
                        Console.WriteLine("Great! Recipe dleted successfully");
                    }
                }

                else if (choice == 2)
                {
                    main.IngredientMenu();
                    int ingredientMenuChoice = Convert.ToInt32(Console.ReadLine());

                    if (ingredientMenuChoice == 1)
                    {
                        if (ingredients.Capacity <= 0)
                            Console.WriteLine("No ingredients found. \n");
                        else
                        {
                            Console.WriteLine("Here are all the ingredients \n");
                            foreach (var ingredient in ingredients)
                                ingredient.Read();
                        }
                    }

                    else if (ingredientMenuChoice == 2)
                    {
                        Console.WriteLine("Please enter the ingredient name: ");
                        string ingredientName = Console.ReadLine();
                        Console.WriteLine("\n Please enter the ingredient description: ");
                        string ingredientDescription = Console.ReadLine();
                        Console.WriteLine("\n Please enter the ingredient calorie per 100g (or press enter to skip): ");
                        int ingredientCalorie = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine("\n \n Great! ingredient added succesfully. ");
                        Ingredient ingredient = new Ingredient();
                        ingredient.Create(ingredientName, ingredientDescription, ingredientCalorie, ingredientCount);
                        ingredientCount++;
                        ingredients.Add(ingredient);
                    }

                    else if (ingredientMenuChoice == 3)
                    {
                        Console.WriteLine("\n Please enter the ID of the ingredient you want to update: ");
                        int updateIngredientID = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine("\n Please enter the new ingredient name(or press entr to skip): ");
                        string newIngredientName = Console.ReadLine();
                        Console.WriteLine("\n Please enter the new ingredient description(or press enter to skip): ");
                        string newRecipeDescription = Console.ReadLine();
                        Console.WriteLine("\n Please enter the new ingredient calorie(or press enter to skip): ");
                        int newIngredientCalorie = Convert.ToInt32(Console.ReadLine());
                        int index = -1;
                        int count = 0;
                        foreach (var value in ingredients)
                        {
                            if (value.getID() == updateIngredientID)
                                index = count;
                            count++;
                        }
                        if (index == -1)
                            Console.WriteLine("This id can not be found");
                        else
                            ingredients[index].Update(newIngredientName, newIngredientCalorie, newRecipeDescription, ingredients, index);
                    }

                    else if (ingredientMenuChoice == 4)
                    {
                        Console.WriteLine("\n Please enter the ID of the ingredient you want to delete: ");
                        int deleteID = Convert.ToInt32(Console.ReadLine());
                        ingredients[deleteID - 1].Delete(ingredients, deleteID);
                        Console.WriteLine("Great! ingredient dleted successfully");
                    }

                }

                else if (choice == 3)
                {
                    main.RatingMenu();
                    int ratingMenuChoice = Convert.ToInt32(Console.ReadLine());

                    if (ratingMenuChoice == 1)
                    {
                        if (ratings.Capacity <= 0)
                            Console.WriteLine("No ratings found. \n");
                        else
                        {
                            Console.WriteLine("Here are all the ingredients \n");
                            foreach (var rating in ratings)
                                rating.Read();
                        }
                    }

                    else if (ratingMenuChoice == 2)
                    {
                        Console.WriteLine("Please enter the rating value: ");
                        double ratingValue = Convert.ToDouble(Console.ReadLine());
                        Rating rating = new Rating();
                        rating.Create(ratingValue, ratingCount);
                        ratingCount++;
                        ratings.Add(rating);
                    }

                    else if (ratingMenuChoice == 3)
                    {
                        Console.WriteLine("\n Please enter the ID of the rating you want to update: ");
                        int updateRatingID = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine("\n Please enter the new rating value(or press entr to skip): ");
                        double newRatingValuie = Convert.ToDouble(Console.ReadLine());
                        int index = -1;
                        int count = 0;
                        foreach (var value in ratings)
                        {
                            if (value.getID() == updateRatingID)
                                index = count;
                            count++;
                        }
                        if (index == -1)
                            Console.WriteLine("This id can not be found");
                        else
                            ratings[index].Update(newRatingValuie, ratings, index);
                    }

                    else if (ratingMenuChoice == 4)
                    {
                        Console.WriteLine("\n Please enter the ID of the rating you want to delete: ");
                        int deleteID = Convert.ToInt32(Console.ReadLine());
                        ratings[deleteID - 1].Delete(ratings, deleteID);
                        Console.WriteLine("Great! rating dleted successfully");
                    }
                }

                else if (choice == 4)
                {
                    Console.WriteLine("Goodbye!");
                }

                else
                {
                    Console.WriteLine("You choice wrong number please try again... \n");
                }
            }
        }
    }
}
