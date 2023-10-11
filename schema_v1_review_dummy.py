import os

value = 180_000

os.mkdir("schema_v1_review_dummy")
for step in range(1, value // 5000 + 1):

    with open(f"schema_v1_review_dummy/review_dummy_{step}.sql", "w", encoding="utf-8") as file:

            file.write("INSERT INTO review (created_at, updated_at, polarity, content, rating, title, positive_tags_count, negative_tags_count)\n")
            file.write("VALUES\n")
            for i in range(1 + (5000 * (step - 1)), 5000 * step):
                file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', 'POSITIVE', 'content{i}', 3, 'title{i}', 3, 3),\n")
            file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', 'POSITIVE', 'content{i + 1}', 3, 'title{i + 1}', 3, 3);\n")