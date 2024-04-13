# RWKV-World-Tokenizer-CPP

Highly optimal trie tokenizer for world written in C++.
It's a little messy rn needs a cleanup (reading python strings gets weird and this is at a state where the trial and error for reading the vocab just worked)

Achieves a 50x speedup over the python trie tokenizer while outputting 1:1 exactly the same.
Will clean it up at some point.

After installing pybind you can just use it like this: 

```python
import world_tokenizer_cpp
tokenizer_cpp = world_tokenizer_cpp.TRIE_TOKENIZER("rwkv_vocab_v20230424.txt")
```

It's a drop in replacement (apart from the fact you can't multiprocess with it, you'll eed to initialise it multiple times).