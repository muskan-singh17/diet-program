#include <stdio.h>
#include <string.h>

#define MAX_NAME 128

typedef struct {
    char name[MAX_NAME];
    int kcal;
} MenuItem;

/* ---------- Utility functions ---------- */

float calcBMI(float w, float h) {
    return w / ((h / 100.0f) * (h / 100.0f));
}

float calcBMR(float w, float h, float a, int gender) {
    if (gender == 1) // Male
        return 88.362f + (13.397f * w) + (4.799f * h) - (5.677f * a);
    else // Female
        return 447.593f + (9.247f * w) + (3.098f * h) - (4.330f * a);
}

float activityFactor(int c) {
    switch (c) {
        case 1: return 1.2f;   // Sedentary
        case 2: return 1.375f; // Light
        case 3: return 1.55f;  // Moderate
        case 4: return 1.725f; // Heavy
        default: return 1.55f;
    }
}

/* ---------- Menus (expanded lists) ---------- */
/* Each array holds MenuItem list and a count. You can add more items easily. */

/* ---------- Vegetarian Gain ---------- */
MenuItem vegGainBreakfast[] = {
    {"Banana shake + Peanut butter toast", 600},
    {"Paneer paratha + Curd", 550},
    {"Vegetable upma + Coconut chutney", 480},
    {"Oats + Milk + Banana + Almonds", 520},
    {"Aloo paratha + Butter + Pickle", 700}
};
int vegGainBreakfastCnt = sizeof(vegGainBreakfast)/sizeof(MenuItem);

MenuItem vegGainMid[] = {
    {"Fruit chaat", 200},
    {"Banana + Peanut butter", 250},
    {"Buttermilk + Chikki", 180},
    {"Paneer cubes + Dry fruits", 250}
};
int vegGainMidCnt = sizeof(vegGainMid)/sizeof(MenuItem);

MenuItem vegGainLunch[] = {
    {"Rajma + Rice + Ghee + Salad", 750},
    {"Chole + Bhature", 850},
    {"Paneer Butter Masala + Naan", 820},
    {"Veg biryani + Raita", 700},
    {"Soya chunk curry + Paratha", 650}
};
int vegGainLunchCnt = sizeof(vegGainLunch)/sizeof(MenuItem);

MenuItem vegGainEvening[] = {
    {"Vegetable sandwich with cheese", 300},
    {"Fruit milkshake", 350},
    {"Bhel puri with peanuts", 250},
    {"Paneer tikka", 320}
};
int vegGainEveningCnt = sizeof(vegGainEvening)/sizeof(MenuItem);

MenuItem vegGainDinner[] = {
    {"Paneer curry + Rice", 700},
    {"Dal makhani + Jeera rice", 800},
    {"Aloo gobi + Roti + Ghee", 600},
    {"Vegetable pulao + Curd", 650},
    {"Soya chaap + Roti", 680}
};
int vegGainDinnerCnt = sizeof(vegGainDinner)/sizeof(MenuItem);

MenuItem vegGainBed[] = {
    {"Milk + Nuts", 250},
    {"Milk + Honey", 180}
};
int vegGainBedCnt = sizeof(vegGainBed)/sizeof(MenuItem);

/* ---------- Non-Vegetarian Gain ---------- */
MenuItem nonVegGainBreakfast[] = {
    {"4 Egg omelette + Bread", 550},
    {"Chicken sandwich + Milk", 600},
    {"Oats + Milk + Eggs", 520},
    {"Cheese omelette + Paratha", 650},
    {"Egg bhurji + Pav", 500}
};
int nonVegGainBreakfastCnt = sizeof(nonVegGainBreakfast)/sizeof(MenuItem);

MenuItem nonVegGainMid[] = {
    {"Banana shake", 350},
    {"Peanut butter smoothie", 300},
    {"Boiled eggs + chikki", 220}
};
int nonVegGainMidCnt = sizeof(nonVegGainMid)/sizeof(MenuItem);

MenuItem nonVegGainLunch[] = {
    {"Chicken curry + Rice", 800},
    {"Fish curry + Rice", 750},
    {"Chicken biryani + Raita", 900},
    {"Egg curry + Paratha", 650},
    {"Butter chicken + Naan", 1000}
};
int nonVegGainLunchCnt = sizeof(nonVegGainLunch)/sizeof(MenuItem);

MenuItem nonVegGainEvening[] = {
    {"Chicken roll", 350},
    {"Grilled chicken", 300},
    {"Chicken tikka", 330},
    {"Egg sandwich", 280}
};
int nonVegGainEveningCnt = sizeof(nonVegGainEvening)/sizeof(MenuItem);

MenuItem nonVegGainDinner[] = {
    {"Grilled chicken + Rice", 700},
    {"Fish + Mashed potato", 650},
    {"Chicken seekh kebab + Roti", 600},
    {"Egg curry + Rice", 550},
    {"Chicken curry + Chapati", 680}
};
int nonVegGainDinnerCnt = sizeof(nonVegGainDinner)/sizeof(MenuItem);

MenuItem nonVegGainBed[] = {
    {"Milk + Almonds", 250},
    {"Milk + Nuts", 250}
};
int nonVegGainBedCnt = sizeof(nonVegGainBed)/sizeof(MenuItem);

/* ---------- Vegetarian Loss ---------- */
MenuItem vegLossBreakfast[] = {
    {"Sprouts + Fruit", 200},
    {"Oats + Water + Apple", 220},
    {"Poha", 250},
    {"Daliya", 300},
    {"Besan chilla", 250}
};
int vegLossBreakfastCnt = sizeof(vegLossBreakfast)/sizeof(MenuItem);

MenuItem vegLossMid[] = {
    {"Green tea + 2 biscuits", 80},
    {"Coconut water", 45},
    {"Apple / Orange", 80}
};
int vegLossMidCnt = sizeof(vegLossMid)/sizeof(MenuItem);

MenuItem vegLossLunch[] = {
    {"2 Roti + Sabzi + Salad", 350},
    {"Brown rice + Dal + Salad", 400},
    {"Khichdi + Curd", 350},
    {"Vegetable soup + Paneer", 300},
    {"Low-oil vegetable pulao", 380}
};
int vegLossLunchCnt = sizeof(vegLossLunch)/sizeof(MenuItem);

MenuItem vegLossEvening[] = {
    {"Fruit bowl", 120},
    {"Clear soup", 70},
    {"Roasted chana", 100},
    {"Green tea + peanuts", 150}
};
int vegLossEveningCnt = sizeof(vegLossEvening)/sizeof(MenuItem);

MenuItem vegLossDinner[] = {
    {"Vegetable soup + Paneer", 250},
    {"Dal + Vegetables", 300},
    {"Salad bowl + Paneer", 220},
    {"Soya chunks salad", 250},
    {"Boiled vegetables", 200}
};
int vegLossDinnerCnt = sizeof(vegLossDinner)/sizeof(MenuItem);

MenuItem vegLossBed[] = {
    {"Warm water / Herbal tea", 5},
    {"Milk (small)", 100}
};
int vegLossBedCnt = sizeof(vegLossBed)/sizeof(MenuItem);

/* ---------- Non-Vegetarian Loss ---------- */
MenuItem nonVegLossBreakfast[] = {
    {"2 Boiled eggs + Tea", 180},
    {"Egg white omelette", 160},
    {"Oats + Egg whites", 250},
    {"Scrambled eggs", 200},
    {"Chicken salad", 220}
};
int nonVegLossBreakfastCnt = sizeof(nonVegLossBreakfast)/sizeof(MenuItem);

MenuItem nonVegLossMid[] = {
    {"Green tea + 2 biscuits", 80},
    {"Coconut water", 45},
    {"1 fruit", 80}
};
int nonVegLossMidCnt = sizeof(nonVegLossMid)/sizeof(MenuItem);

MenuItem nonVegLossLunch[] = {
    {"Grilled chicken + Veggies", 450},
    {"Grilled fish + Veggies", 400},
    {"Chicken soup + Salad", 350},
    {"Boiled chicken + Salad", 320},
    {"Egg curry (2 eggs) + Roti", 350}
};
int nonVegLossLunchCnt = sizeof(nonVegLossLunch)/sizeof(MenuItem);

MenuItem nonVegLossEvening[] = {
    {"Chicken soup", 120},
    {"Fruit salad", 100},
    {"Egg whites", 70},
    {"Black coffee", 0}
};
int nonVegLossEveningCnt = sizeof(nonVegLossEvening)/sizeof(MenuItem);

MenuItem nonVegLossDinner[] = {
    {"2 Egg whites + Soup", 200},
    {"Fish + Salad", 250},
    {"Grilled chicken", 300},
    {"Chicken + Veg soup", 280},
    {"Omelette (2 eggs) + Veggies", 300}
};
int nonVegLossDinnerCnt = sizeof(nonVegLossDinner)/sizeof(MenuItem);

MenuItem nonVegLossBed[] = {
    {"Lemon water / Green tea", 0},
    {"Small glass milk", 100}
};
int nonVegLossBedCnt = sizeof(nonVegLossBed)/sizeof(MenuItem);


/* ---------- Helper to display menu and get user's choice ---------- */
int showMenuAndGetChoice(MenuItem menu[], int count, const char *mealName) {
    int i, choice;
    printf("\n%s\n", mealName);
    for (i = 0; i < count; ++i) {
        printf("%d) %s (%d kcal)\n", i + 1, menu[i].name, menu[i].kcal);
    }
    printf("0) Skip %s\n", mealName);
    printf("Enter choice (number): ");
    if (scanf("%d", &choice) != 1) { // input validation basic
        while (getchar() != '\n');
        return 0;
    }
    if (choice < 0 || choice > count) {
        printf("Invalid choice. Selecting 0 (skip).\n");
        return 0;
    }
    return choice; // 0..count
}

/* ---------- Macro calc & print ---------- */
void printMacroTargets(float targetCalories, int goal) {
    // goal: 1 = gain (40/40/20), 2 = loss (45/35/20)
    float pPerc, cPerc, fPerc;
    if (goal == 1) { pPerc = 0.40f; cPerc = 0.40f; fPerc = 0.20f; }
    else { pPerc = 0.45f; cPerc = 0.35f; fPerc = 0.20f; }

    float protein_kcal = targetCalories * pPerc;
    float carbs_kcal   = targetCalories * cPerc;
    float fats_kcal    = targetCalories * fPerc;

    float protein_g = protein_kcal / 4.0f;
    float carbs_g   = carbs_kcal / 4.0f;
    float fats_g    = fats_kcal / 9.0f;

    printf("\nRecommended daily macros for target ~%.0f kcal:\n", targetCalories);
    printf("Protein: %.0f g (%.0f kcal)\n", protein_g, protein_kcal);
    printf("Carbs  : %.0f g (%.0f kcal)\n", carbs_g, carbs_kcal);
    printf("Fats   : %.0f g (%.0f kcal)\n", fats_g, fats_kcal);
}

/* ---------- Main program ---------- */

int main() {
    float weight, height, age, bmi, bmr, tdee;
    int gender, activity, goal, dietType;

    printf("===== ADVANCED DIET + CALORIE RECOMMENDATION SIMULATOR =====\n");

    printf("Enter your weight (kg): ");
    scanf("%f", &weight);

    printf("Enter your height (cm): ");
    scanf("%f", &height);

    printf("Enter your age (years): ");
    scanf("%f", &age);

    printf("Select Gender:\n1. Male\n2. Female\nEnter choice: ");
    scanf("%d", &gender);

    printf("\nSelect Activity Level:\n1. Sedentary\n2. Light\n3. Moderate\n4. Heavy\nEnter choice: ");
    scanf("%d", &activity);

    bmi = calcBMI(weight, height);
    bmr = calcBMR(weight, height, age, gender);
    tdee = bmr * activityFactor(activity);

    printf("\n--- Results ---\n");
    printf("BMI: %.2f\n", bmi);
    printf("BMR: %.2f kcal/day\n", bmr);
    printf("Maintenance (TDEE): %.2f kcal/day\n", tdee);

    printf("\nSelect Goal:\n1. Weight Gain\n2. Weight Loss\n3. Exit\nEnter: ");
    scanf("%d", &goal);
    if (goal == 3) {
        printf("Exiting.\n");
        return 0;
    }
    if (!(goal == 1 || goal == 2)) {
        printf("Invalid goal selection. Exiting.\n");
        return 0;
    }

    printf("\nDiet Type:\n1. Vegetarian\n2. Non-Vegetarian\nEnter: ");
    scanf("%d", &dietType);
    if (!(dietType == 1 || dietType == 2)) {
        printf("Invalid diet type. Defaulting to Vegetarian.\n");
        dietType = 1;
    }

    float recLow, recHigh, target;
    if (goal == 1) { // gain
        recLow = tdee + 300.0f;
        recHigh = tdee + 500.0f;
        target = (recLow + recHigh) / 2.0f; // mid target
    } else { // loss
        recLow = tdee - 500.0f;
        recHigh = tdee - 300.0f;
        target = (recLow + recHigh) / 2.0f; // mid target
    }

    printf("\nRecommended intake: %.0f - %.0f kcal/day (target ~%.0f kcal)\n", recLow, recHigh, target);
    printMacroTargets(target, goal);

    /* ---------- Meal selection flow ---------- */
    int choice;
    int totalCalories = 0;

    // Breakfast
    if (dietType == 1 && goal == 1) { // veg gain breakfast
        choice = showMenuAndGetChoice(vegGainBreakfast, vegGainBreakfastCnt, "BREAKFAST (Vegetarian - Gain)");
        if (choice > 0) totalCalories += vegGainBreakfast[choice-1].kcal;
    } else if (dietType == 2 && goal == 1) {
        choice = showMenuAndGetChoice(nonVegGainBreakfast, nonVegGainBreakfastCnt, "BREAKFAST (Non-Veg - Gain)");
        if (choice > 0) totalCalories += nonVegGainBreakfast[choice-1].kcal;
    } else if (dietType == 1 && goal == 2) {
        choice = showMenuAndGetChoice(vegLossBreakfast, vegLossBreakfastCnt, "BREAKFAST (Vegetarian - Loss)");
        if (choice > 0) totalCalories += vegLossBreakfast[choice-1].kcal;
    } else {
        choice = showMenuAndGetChoice(nonVegLossBreakfast, nonVegLossBreakfastCnt, "BREAKFAST (Non-Veg - Loss)");
        if (choice > 0) totalCalories += nonVegLossBreakfast[choice-1].kcal;
    }

    // Mid-morning
    if (dietType == 1 && goal == 1) {
        choice = showMenuAndGetChoice(vegGainMid, vegGainMidCnt, "MID-MORNING SNACK (Vegetarian - Gain)");
        if (choice > 0) totalCalories += vegGainMid[choice-1].kcal;
    } else if (dietType == 2 && goal == 1) {
        choice = showMenuAndGetChoice(nonVegGainMid, nonVegGainMidCnt, "MID-MORNING SNACK (Non-Veg - Gain)");
        if (choice > 0) totalCalories += nonVegGainMid[choice-1].kcal;
    } else if (dietType == 1 && goal == 2) {
        choice = showMenuAndGetChoice(vegLossMid, vegLossMidCnt, "MID-MORNING SNACK (Vegetarian - Loss)");
        if (choice > 0) totalCalories += vegLossMid[choice-1].kcal;
    } else {
        choice = showMenuAndGetChoice(nonVegLossMid, nonVegLossMidCnt, "MID-MORNING SNACK (Non-Veg - Loss)");
        if (choice > 0) totalCalories += nonVegLossMid[choice-1].kcal;
    }

    // Lunch
    if (dietType == 1 && goal == 1) {
        choice = showMenuAndGetChoice(vegGainLunch, vegGainLunchCnt, "LUNCH (Vegetarian - Gain)");
        if (choice > 0) totalCalories += vegGainLunch[choice-1].kcal;
    } else if (dietType == 2 && goal == 1) {
        choice = showMenuAndGetChoice(nonVegGainLunch, nonVegGainLunchCnt, "LUNCH (Non-Veg - Gain)");
        if (choice > 0) totalCalories += nonVegGainLunch[choice-1].kcal;
    } else if (dietType == 1 && goal == 2) {
        choice = showMenuAndGetChoice(vegLossLunch, vegLossLunchCnt, "LUNCH (Vegetarian - Loss)");
        if (choice > 0) totalCalories += vegLossLunch[choice-1].kcal;
    } else {
        choice = showMenuAndGetChoice(nonVegLossLunch, nonVegLossLunchCnt, "LUNCH (Non-Veg - Loss)");
        if (choice > 0) totalCalories += nonVegLossLunch[choice-1].kcal;
    }

    // Evening snack
    if (dietType == 1 && goal == 1) {
        choice = showMenuAndGetChoice(vegGainEvening, vegGainEveningCnt, "EVENING SNACK (Vegetarian - Gain)");
        if (choice > 0) totalCalories += vegGainEvening[choice-1].kcal;
    } else if (dietType == 2 && goal == 1) {
        choice = showMenuAndGetChoice(nonVegGainEvening, nonVegGainEveningCnt, "EVENING SNACK (Non-Veg - Gain)");
        if (choice > 0) totalCalories += nonVegGainEvening[choice-1].kcal;
    } else if (dietType == 1 && goal == 2) {
        choice = showMenuAndGetChoice(vegLossEvening, vegLossEveningCnt, "EVENING SNACK (Vegetarian - Loss)");
        if (choice > 0) totalCalories += vegLossEvening[choice-1].kcal;
    } else {
        choice = showMenuAndGetChoice(nonVegLossEvening, nonVegLossEveningCnt, "EVENING SNACK (Non-Veg - Loss)");
        if (choice > 0) totalCalories += nonVegLossEvening[choice-1].kcal;
    }

    // Dinner
    if (dietType == 1 && goal == 1) {
        choice = showMenuAndGetChoice(vegGainDinner, vegGainDinnerCnt, "DINNER (Vegetarian - Gain)");
        if (choice > 0) totalCalories += vegGainDinner[choice-1].kcal;
    } else if (dietType == 2 && goal == 1) {
        choice = showMenuAndGetChoice(nonVegGainDinner, nonVegGainDinnerCnt, "DINNER (Non-Veg - Gain)");
        if (choice > 0) totalCalories += nonVegGainDinner[choice-1].kcal;
    } else if (dietType == 1 && goal == 2) {
        choice = showMenuAndGetChoice(vegLossDinner, vegLossDinnerCnt, "DINNER (Vegetarian - Loss)");
        if (choice > 0) totalCalories += vegLossDinner[choice-1].kcal;
    } else {
        choice = showMenuAndGetChoice(nonVegLossDinner, nonVegLossDinnerCnt, "DINNER (Non-Veg - Loss)");
        if (choice > 0) totalCalories += nonVegLossDinner[choice-1].kcal;
    }

    // Bedtime (optional)
    if (dietType == 1 && goal == 1) {
        choice = showMenuAndGetChoice(vegGainBed, vegGainBedCnt, "BEDTIME (Vegetarian - Gain)");
        if (choice > 0) totalCalories += vegGainBed[choice-1].kcal;
    } else if (dietType == 2 && goal == 1) {
        choice = showMenuAndGetChoice(nonVegGainBed, nonVegGainBedCnt, "BEDTIME (Non-Veg - Gain)");
        if (choice > 0) totalCalories += nonVegGainBed[choice-1].kcal;
    } else if (dietType == 1 && goal == 2) {
        choice = showMenuAndGetChoice(vegLossBed, vegLossBedCnt, "BEDTIME (Vegetarian - Loss)");
        if (choice > 0) totalCalories += vegLossBed[choice-1].kcal;
    } else {
        choice = showMenuAndGetChoice(nonVegLossBed, nonVegLossBedCnt, "BEDTIME (Non-Veg - Loss)");
        if (choice > 0) totalCalories += nonVegLossBed[choice-1].kcal;
    }

    /* ---------- Summary ---------- */
    printf("\n\n========== DAILY SUMMARY ==========\n");
    printf("Total Selected Calories: %d kcal\n", totalCalories);
    printf("Recommended Range: %.0f - %.0f kcal (target ~%.0f kcal)\n", recLow, recHigh, target);

    if (totalCalories < recLow) {
        printf("Status: Your selected meals are BELOW the recommended range by %.0f kcal.\n", recLow - totalCalories);
    } else if (totalCalories > recHigh) {
        printf("Status: Your selected meals are ABOVE the recommended range by %.0f kcal.\n", totalCalories - recHigh);
    } else {
        printf("Status: Your selected meals are WITHIN the recommended range. Good!\n");
    }

    /* Compare with macro targets (show how many kcal remain/over for target) */
    float diff = (float)totalCalories - target;
    if (diff < 0.0f) {
        printf("You are %.0f kcal under the target (~%.0f kcal). Consider adding a snack or increasing portion sizes.\n", -diff, target);
    } else if (diff > 0.0f) {
        printf("You are %.0f kcal above the target (~%.0f kcal). Consider reducing portion sizes or skipping high-calorie items.\n", diff, target);
    } else {
        printf("You exactly matched the target calories. Nice!\n");
    }

    printf("\n");
    printMacroTargets(target, goal);

    printf("\nTip: This simulator shows calories and macro targets. For precise macro distribution per food item, you can expand each MenuItem to include protein/carbs/fat values and sum them similarly.\n");
    printf("Program finished.\n");

    return 0;
}
