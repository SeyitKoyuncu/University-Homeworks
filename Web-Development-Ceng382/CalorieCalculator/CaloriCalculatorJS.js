var totalCalories = 0;

function isNumber(value) {
    if (typeof value === "string") {
        return !isNaN(value);
    }
}

function addIngredient() {
	var name = document.getElementById("name").value;
    var amount = document.getElementById("amount").value;
    var calorie = document.getElementById("calories").value;


    if(!isNumber(amount) && !isNumber(calorie))
    {
        alert("Amount or Calorie is not number... Please write numbers");
        return;
    }

    if(amount < 0)
    {
        alert("Amount can not be negative number");
        return;
    }

    if(calorie < 0)
    {
        alert("Amount can not be negative number");
        return;
    }

    if(calorie / 100 > 20)
    {
        alert("Calorie can not be more than 20 per gram");
        return;
    }

	var li = document.createElement("li");

    if(name && amount && calorie)
	    var text = document.createTextNode(name + " " + amount + " gr " + calorie + " cal./100gr");
    else
        alert("Please fill every input!");

    if(text)
    {
        li.appendChild(text);
        // Add the list item to the unordered list
        var ul = document.createElement("ul");
        ul.appendChild(li);

        // Add the ordered list to the ingredients_list div element
        var listDiv = document.getElementById("ingredients_list");
        listDiv.appendChild(ul);

        calculateCalories(calorie, amount);
    }
}

function calculateCalories(calorie, amount)
{
    totalCalories += calorie * (amount / 100);
}

function writeTotalCalori()
{
    var alertMessage = "";
    var alertColor = "";

    if(totalCalories <= 100 && totalCalories >= 0)
    {
        alertMessage = " Very healthy";
        alertColor = "green";
    }

    else if(totalCalories <= 200 && totalCalories >= 101)
    {
        alertMessage = " Healthy";
        alertColor = "blue";
    }

    else if(totalCalories <= 300 && totalCalories >= 201)
    {
        alertMessage = " It is good to stay away";
        alertColor = "orange";
    }

    else if(totalCalories >= 301)
    {
        alertMessage = " Stay away";
        alertColor = "red";
    }

    else
    {
        alert("You must write wrong calories or amounts. Please check it.");
        return;
    }

    var p = document.createElement("p");
    var text = document.createTextNode("Total calories: " + totalCalories + " cal. ");
    var alertSpan = document.createElement("span");

    alertSpan.style.color = alertColor;
    alertSpan.textContent = alertMessage;

    p.appendChild(text);
    p.appendChild(alertSpan);
    p.style.fontSize = "15px";

    var listDiv = document.getElementById("ingredients_list");
    listDiv.appendChild(p);
}