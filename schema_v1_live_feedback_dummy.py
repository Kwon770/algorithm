value = 180_000

statusSets = [
    (0, 0, 0),
    (1, 0, 0),
    (1, 0, 1),
    (1, 1, 0),
]

os.mkdir("schema_v1_live_feedback_dummy")
for step in range(1, value // 5000 + 1):

    with open(f"schema_v1_live_feedback_dummy/feedback_dummy_{step}.sql", "w", encoding="utf-8") as file:

        file.write("INSERT INTO live_feedback (created_at, updated_at, customer_media_url, customer_message, is_handled, is_reported, is_solved, seller_message)\n")
        file.write("VALUES\n")
        for i in range(1 + (5000 * (step - 1)), 5000 * step):
            file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', 'custmerMedia1{i}', 'customerMessage{i}', {statusSets[i % len(statusSets)][0]}, {statusSets[i % len(statusSets)][1]}, {statusSets[i % len(statusSets)][2]}, 'sellerMessage{i}'),\n")
        file.write(f"('2023-09-01 12:00:00', '2023-09-01 12:00:00', 'custmerMedia1{i + 1}', 'customerMessage{i + 1}', {statusSets[i % len(statusSets)][0]}, {statusSets[i % len(statusSets)][1]}, {statusSets[i % len(statusSets)][2]}, 'sellerMessage{i}');\n")