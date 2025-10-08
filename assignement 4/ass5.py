def calculate_precision_recall(answer_set,relevant_set):
    A= set(answer_set)
    rq1= set(relevant_set)


    true_positives = A.intersection(rq1)

    precision = len(true_positives)/len(A) if A else 0

    recall= len(true_positives)/len(rq1) if rq1 else 0

    return precision,recall


def calculate_f_measure(precision, recall):
    if precision + recall == 0:
        return 0
    return 2 * precision * recall / (precision + recall)


def calculate_e_measure(f_measure):
    return 1 - f_measure

answer_set = ["D1","D2","D3","D4"]
relevant_set = ["D2","D4","D5"]

precision,recall = calculate_precision_recall(answer_set,relevant_set)

print("Precision is:",precision)
print("Recall is:",recall)
f_measure = calculate_f_measure(precision, recall)
e_measure = calculate_e_measure(f_measure)

print(f"F-measure: {f_measure:.2f}")
print(f"E-measure: {e_measure:.2f}")