value = 180_000

travels = [i for i in range(1, 11)]
customers = [i for i in range(1, 1001)]

os.mkdir("schema_v1_reservation")
for step in range(1, value // 5000 + 1):

    with open(f"schema_v1_reservation/schema_v1_reservation_dummy{step}.sql", "w", encoding="utf-8") as file:

            file.write("INSERT INTO reservation (created_at, updated_at, partner_custom_id, start_date_time, end_date_time, customer_id, travel_product_id, review_id, live_satisfaction_id, live_feedback_id)\n")
            file.write("VALUES\n")
            for i in range(1 + (5000 * (step - 1)), 5000 * step):
                file.write(f"('2023-08-30 12:00:00', '2023-08-30 12:00:00', 'RESERVATION_{i}', '2023-10-18T13:00:00', '2023-10-19T12:00:00', {customers[i % len(customers)]}, {travels[i % len(travels)]}, {i}, {i}, {i}),\n")
            file.write(f"('2023-08-30 12:00:00', '2023-08-30 12:00:00', 'RESERVATION_{i + 1}', '2023-10-18T13:00:00', '2023-10-19T12:00:00', {customers[i % len(customers)]}, {travels[i % len(travels)]}, {i + 1}, {i + 1}, {i + 1});\n")