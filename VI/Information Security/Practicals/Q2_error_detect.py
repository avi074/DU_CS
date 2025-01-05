import modules.basic_functions as func


def check_parity_bit(data):
    # Count the number of ones in the data
    count = 0
    for bit in data:
        if bit == 1:
            count += 1

    # Check the parity bit
    return (count % 2 == 0)  # True = No Error, False = Error


def add_parity_bit(data):
    # Add a parity bit to make the count even
    if check_parity_bit(data):
        data.append(0)
    else:
        data.append(1)

    return data


# Example usage
print("\n\t\t Practical 2 \n")
data = [1, 0, 1, 1]  # Data bits
encoded_data = add_parity_bit(data)  # Add a parity bit
print("Encoded data with parity : %s" % encoded_data)

# Simulate an error by flipping a bit
encoded_data[2] = 0
print("Received data with error : %s" % encoded_data)

# Check the parity bit and detect errors
error_detected = not check_parity_bit(encoded_data)

if error_detected:
    func.e_print("Error Detected !!!", 'error')
else:
    func.e_print("No Error Detected !!!", 'info')
