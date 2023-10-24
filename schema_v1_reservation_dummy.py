import datetime
import itertools
from random import shuffle

# value = 150_000
value = 450_000


# products = [i for i in range(1, 11)]
products = [i for i in range(11, 31)]
products_cycle = itertools.cycle(products)
customers = [i for i in range(1, 1001)]
customers_cycle = itertools.cycle(customers)


def generate_dates(start_date, end_date):
    date_list = []
    current_date = start_date
    while current_date <= end_date:
        date_list.append(current_date)
        current_date += datetime.timedelta(days=1)

    shuffle(date_list)
    return date_list


start_date = datetime.datetime(2023, 1, 1)
end_date = datetime.datetime(2023, 10, 18)

all_dates = generate_dates(start_date, end_date)
date_cycle = itertools.cycle(all_dates)


os.mkdir("schema_v1_reservation")
# for step in range(1, value // 5000 + 1):
for step in range(155_000 // 5000, value // 5000 + 1):

    with open(f"schema_v1_reservation/schema_v1_reservation_dummy{step}.sql", "w", encoding="utf-8") as file:

            file.write("INSERT INTO reservation (created_at, updated_at, partner_custom_id, start_date_time, end_date_time, travel_product_id, customer_id, review_id, live_satisfaction_id, live_feedback_id)\n")
            file.write("VALUES\n")
            for i in range(1 + (5000 * (step - 1)), 5000 * step):
                created_at = next(date_cycle)
                file.write(f"('{created_at}', '{created_at}', 'RESERVATION_{i}', '2023-10-18T13:00:00', '2023-10-19T12:00:00', {next(products_cycle)}, {next(customers_cycle)}, {i}, {i}, {i}),\n")
            created_at = next(date_cycle)
            file.write(f"('{created_at}', '{created_at}', 'RESERVATION_{i + 1}', '2023-10-18T13:00:00', '2023-10-19T12:00:00', {next(products_cycle)}, {next(customers_cycle)}, {i + 1}, {i + 1}, {i + 1});\n")