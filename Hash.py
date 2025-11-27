# 1. Import the library
import hashlib
# 2. Prepare the data (encode to bytes)
message = "Hello, World!"
data = message.encode('utf-8')
# 3. Compute the hash
hash_object = hashlib.sha256(data)
# 4. Format the output (get hex string)
hex_digest = hash_object.hexdigest()
print(hex_digest)