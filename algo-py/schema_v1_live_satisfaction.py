import os

value = 180_000

os.mkdir("schema_v1_live_satisfaction_dummy")
for step in range(1, value // 5000 + 1):

    with open(f"schema_v1_live_satisfaction_dummy/satisfaction_dummy_{step}.sql", "w", encoding="utf-8") as file:

        file.write(
            "INSERT INTO live_satisfaction (created_at, updated_at, dissatisfied_review_property, rating, satisfied_review_property)\n")
        file.write("VALUES\n")
        for i in range(1 + (5000 * (step - 1)), 5000 * step):
            file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', 'KINDNESS', 3, 'LOCATION'),\n")
        file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', 'KINDNESS', 3, 'LOCATION');\n")
