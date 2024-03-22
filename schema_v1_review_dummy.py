import itertools
import os

reviews_count = 600_0000
review_ids_cycle = itertools.cycle([i for i in range(1, reviews_count + 1)])
review_images_count = reviews_count
review_tags_count = reviews_count * 3

os.mkdir("schema_v1_review_dummy")
for step in range(1, reviews_count // 5000 + 1):

    with open(f"schema_v1_review_dummy/review_dummy_{step}.sql", "w", encoding="utf-8") as file:

            file.write("INSERT INTO review (created_at, updated_at, polarity, content, rating, title, positive_tags_count, negative_tags_count, reservation_id)\n")
            file.write("VALUES\n")
            for i in range(1 + (5000 * (step - 1)), 5000 * step):
                file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', 'POSITIVE', 'content{i}', 3, 'title{i}', 2, 1, {i}),\n")
            file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', 'POSITIVE', 'content{i + 1}', 3, 'title{i + 1}', 2, 1, {i});\n")


os.mkdir("schema_v1_review_image_dummy")
for step in range(1, review_images_count // 5000 + 1):

    with open(f"schema_v1_review_image_dummy/image_dummy_{step}.sql", "w", encoding="utf-8") as file:

            file.write("INSERT INTO review_image (created_at, updated_at, url, review_id)\n")
            file.write("VALUES\n")
            for i in range(1 + (5000 * (step - 1)), 5000 * step):
                file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', 'testurl{i}.com', {i}),\n")
            file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', 'testurl{i + 1}.com', {i});\n")


index_cases = [(0, 1), (2, 3), (4, 5)]
index_cases_cycle = itertools.cycle(index_cases)
tags = [('먼지', 'CLEANNESS'), ('냄새', 'CLEANNESS'), ('친절', 'KINDNESS')]
tags_cycle = itertools.cycle(tags)
polarites = ['NEGATIVE', 'POSITIVE']
polarites_cycle = itertools.cycle(polarites)

os.mkdir("schema_v1_review_tag_dummy")
for step in range(1, review_tags_count // 5000 + 1):

    with open(f"schema_v1_review_tag_dummy/tag_dummy_{step}.sql", "w", encoding="utf-8") as file:

            file.write("INSERT INTO review_tag (created_at, updated_at, keyword, polarity, property, start_index, end_index, review_id)\n")
            file.write("VALUES\n")
            for i in range(1 + (5000 * (step - 1)), 5000 * step):
                indexes = next(index_cases_cycle)
                file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', '{next(tags_cycle)[0]}', '{next(polarites_cycle)}', '{next(tags_cycle)[1]}', {indexes[0]}, {indexes[1]}, {next(review_ids_cycle)}),\n")
            indexes = next(index_cases_cycle)
            file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', '{next(tags_cycle)[0]}', '{next(polarites_cycle)}', '{next(tags_cycle)[1]}', {indexes[0]}, {indexes[1]}, {next(review_ids_cycle)});\n")