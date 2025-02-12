alphabet = "abcdefghijklmnopqrstuvwxyz"

def caeser_decrypt(message, offset):
  decrypted_message = ""
  for letter in message:
    idx = alphabet.find(letter)
    if idx < 0:
      decrypted_message += letter
    else:
      decrypted_idx = idx + offset
      if decrypted_idx >= len(alphabet):
        decrypted_idx -= len(alphabet)
      decrypted_message += alphabet[decrypted_idx]
  #print(decrypted_message)
  return decrypted_message

def caeser_encrypt(message, offset):
  encrypted_message = ""
  for letter in message:
    idx = alphabet.find(letter)
    if idx < 0:
      encrypted_message += letter
    else:
      encrypted_idx = idx - offset
      if encrypted_idx < 0:
        encrypted_idx = len(alphabet) + encrypted_idx 
      encrypted_message += alphabet[encrypted_idx]
  #print(encrypted_message)
  return encrypted_message

def get_keyword_phrase(message, keyword):
  keyword_phrase = ""
  keyword_idx = 0
  for letter in message:
    idx = alphabet.find(letter)
    if idx < 0:
      keyword_phrase += letter
    else:
      keyword_phrase += keyword[keyword_idx]
      if keyword_idx == len(keyword) - 1:
        keyword_idx = 0
      else:
        keyword_idx += 1
  return keyword_phrase

def vigenere_encode(message, keyword):
  keyword_phrase = get_keyword_phrase(message, keyword)
  # print(keyword_phrase)
  encoded_message = ""
  for idx in range(len(message)):
    if alphabet.find(message[idx]) < 0:
      encoded_message += message[idx]
    else:
      keyword_offset = alphabet.find(keyword_phrase[idx])
      encoded_message += caeser_encrypt(message[idx], keyword_offset)
  print(encoded_message)

def vigenere_decode(message, keyword):
  keyword_phrase = get_keyword_phrase(message, keyword)
  # print(keyword_phrase)
  decoded_message = ""
  for idx in range(len(message)):
    if alphabet.find(message[idx]) < 0:
      decoded_message += message[idx]
    else:
      keyword_offset = alphabet.find(keyword_phrase[idx])
      decoded_message += caeser_decrypt(message[idx], keyword_offset)
  print(decoded_message)


#message = "xuo jxuhu! jxyi yi qd unqcfbu ev q squiqh syfxuh. muhu oek qrbu je tusetu yj? y xefu ie! iudt cu q cuiiqwu rqsa myjx jxu iqcu evviuj!"
    
#caeser_decrypt(message, 10)
#caeser_encrypt("hello! yes, it was fairly simple to decode it... once one figured out how to do the encryption, of course. how's it going over there?", 10)

#caeser_decrypt("jxu evviuj veh jxu iusedt cuiiqwu yi vekhjuud.", 10)

#caeser_decrypt("bqdradyuzs ygxfubxq omqemd oubtqde fa oapq kagd yqeemsqe ue qhqz yadq eqogdq!", 14)
                        
#caeser_decrypt("vhfinmxkl atox kxgwxkxw tee hy maxlx hew vbiaxkl hulhexmx. px'ee atox mh kxteer lmxi ni hnk ztfx by px ptgm mh dxxi hnk fxlltzxl ltyx.", 7)



test_message = "barry is the spy"
test_keyword = "dog"
test_result = "ymlok cp fbb ejv"

message = "txm srom vkda gl lzlgzr qpdb? fepb ejac! ubr imn tapludwy mhfbz cza ruxzal wg zztylktoikqq!"
keyword = "friends"

vigenere_encode(test_message, test_keyword)
vigenere_decode("ymlok cp fbb ejv", "dog")
vigenere_decode(message, keyword)
