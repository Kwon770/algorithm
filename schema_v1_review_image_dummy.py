import os

value = 360_000
reviews = [i for i in range(1, 180_001)]

os.mkdir("schema_v1_review_image_dummy")
for step in range(1, value // 5000 + 1):

    with open(f"schema_v1_review_image_dummy/image_dummy_{step}.sql", "w", encoding="utf-8") as file:

            file.write("INSERT INTO review_image (created_at, updated_at, url, review_id)\n")
            file.write("VALUES\n")
            for i in range(1 + (5000 * (step - 1)), 5000 * step):
                file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', 'testurl{i}.com', {reviews[i % len(reviews)]}),\n")
            file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', 'testurl{i + 1}.com', {reviews[i % len(reviews)]});\n")