def calculate_precision_recall(answer_set,relevant_set):
    A= set(answer_set)
    rq1= set(relevant_set)


    true_positives = A.intersection(rq1)

    precision = len(true_positives)/len(A) if A else 0

    recall= len(true_positives)/len(rq1) if rq1 else 0

    return precision,recall

answer_set = ["D1","D2","D3","D4"]
relevant_set = ["D2","D4","D5"]

precision,recall = calculate_precision_recall(answer_set,relevant_set)

print(precision)
print("Recall is:",recall)
