import tensorflow as tf

hw = tf.constant("Hello World!")

sess = tf.Session()

print((sess.run(hw)).decode("ascii"))
