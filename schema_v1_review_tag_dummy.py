import os

value = 900_000
reviews = [i for i in range(1, 180_001)]
indexs = [(0,1), (2,3), (4,5)]
tags = [('먼지', 'CLEANNESS'), ('냄새', 'CLEANNESS'), ('친절', 'KINDNESS')]
polarites = ['NEGATIVE', 'POSITIVE']

os.mkdir("schema_v1_review_tag_dummy")
for step in range(1, value // 5000 + 1):

    with open(f"schema_v1_review_tag_dummy/tag_dummy_{step}.sql", "w", encoding="utf-8") as file:

            file.write("INSERT INTO review_tag (created_at, updated_at, keyword, polarity, property, start_index, end_index, review_id)\n")
            file.write("VALUES\n")
            for i in range(1 + (5000 * (step - 1)), 5000 * step):
                file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', '{tags[i % len(tags)][0]}', '{polarites[i % len(polarites)]}', '{tags[i % len(tags)][1]}', {indexs[i % len(indexs)][0]}, {indexs[i % len(indexs)][1]}, {reviews[i % len(reviews)]}),\n")
            file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', '{tags[i % len(tags)][0]}', '{polarites[i % len(polarites)]}', '{tags[i % len(tags)][1]}', {indexs[i % len(indexs)][0]}, {indexs[i % len(indexs)][1]}, {reviews[i % len(reviews)]});\n")