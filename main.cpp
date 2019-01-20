#include "HashTable.h"
#include <gtest/gtest.h>

TEST(HashTableTest, Constructor) {
    ASSERT_NO_THROW(HashTable a);
}

TEST(HashTableTest, CopyConstructor) {
    HashTable a;
    ASSERT_NO_THROW(HashTable b = a);
}

TEST(HashTableTest, TestInsert) {
    HashTable a;
    Value val;
    ASSERT_EQ(a.size(), 0);
    for (int i = 0; i < 10; ++i) {
        ASSERT_EQ(a.size(), i);
        val.age = std::rand()%100;
        val.weight = std::rand()%100;
        EXPECT_TRUE(a.insert("Key" + std::to_string(i), val));
    }
    for (int i = 0; i < 10; ++i) {
        EXPECT_TRUE(a.contains("Key" + std::to_string(i)));
    }
}

TEST(HashTableTest, InsertRehashing) {
    HashTable a;
    Value val;
    for (int i = 0; i < 100; ++i) {
        val.age = std::rand()%100;
        val.weight = std::rand()%100;
        EXPECT_TRUE(a.insert("Key" + std::to_string(i), val));
    }
    for (int i = 0; i < 100; ++i) {
        EXPECT_TRUE(a.contains("Key" + std::to_string(i)));
    }
}

TEST(HashTableTest, Contains) {
    HashTable a;
    Value val;
    for (int i = 0; i < 500; ++i) {
        val.age = std::rand()%100;
        val.weight = std::rand()%100;
        EXPECT_TRUE(a.insert("Key" + std::to_string(i), val));
    }
    for (int i = 0; i < 500; ++i) {
        EXPECT_TRUE(a.contains("Key" + std::to_string(i)));
    }
    EXPECT_FALSE(a.contains("Key" + std::to_string(550)));
}

TEST(HashTableTest, Erase) {
    HashTable a;
    Value val;
    EXPECT_FALSE(a.erase("NotKey"));
    for (int i = 0; i < 500; ++i) {
        val.age = std::rand()%100;
        val.weight = std::rand()%100;
        EXPECT_TRUE(a.insert("Key" + std::to_string(i), val));
    }
    for (int i = 0; i < 500; ++i) {
        EXPECT_TRUE(a.contains("Key" + std::to_string(i)));
    }
    for (int i = 100; i < 300; ++i) {
        EXPECT_TRUE(a.erase("Key" + std::to_string(i)));
    }
    for (int i = 0; i < 100; ++i) {
        EXPECT_TRUE(a.contains("Key" + std::to_string(i)));
    }
    for (int i = 100; i < 300; ++i) {
        EXPECT_FALSE(a.contains("Key" + std::to_string(i)));
    }
    for (int i = 301; i < 500; ++i) {
        EXPECT_TRUE(a.contains("Key" + std::to_string(i)));
    }

}

TEST(HashTableTest, Clear) {
    HashTable a;
    Value val;
    for (int i = 0; i < 500; ++i) {
        val.age = std::rand()%100;
        val.weight = std::rand()%100;
        EXPECT_TRUE(a.insert("Key" + std::to_string(i), val));
    }
    for (int i = 0; i < 500; ++i) {
        EXPECT_TRUE(a.contains("Key" + std::to_string(i)));
    }
    ASSERT_EQ(a.size(), 500);
    a.clear();
    ASSERT_EQ(a.size(), 0);
}

TEST(HashTableTest, Size) {
    HashTable a;
    Value val;
    for (int i = 0; i < 500; ++i) {
        val.age = std::rand()%100;
        val.weight = std::rand()%100;
        ASSERT_EQ(a.size(), i);
        EXPECT_TRUE(a.insert("Key" + std::to_string(i), val));
    }
    for (int i = 0; i < 500; ++i) {
        EXPECT_TRUE(a.contains("Key" + std::to_string(i)));
    }
}

TEST(HashTableTest, Empty) {
    HashTable a;
    Value val;
    EXPECT_TRUE(a.empty());
    for (int i = 0; i < 500; ++i) {
        val.age = std::rand()%100;
        val.weight = std::rand()%100;
        EXPECT_TRUE(a.insert("Key" + std::to_string(i), val));
        EXPECT_FALSE(a.empty());
    }
    for (int i = 0; i < 500; ++i) {
        EXPECT_TRUE(a.contains("Key" + std::to_string(i)));
    }
}

TEST(HashTableTest, OperatorEq) {
    HashTable a;
    HashTable b;
    Value val1;
    Value val2;
    for (int i = 0; i < 500; ++i) {
        val1.age = std::rand()%100;
        val1.weight = std::rand()%100;
        EXPECT_TRUE(a.insert("Key" + std::to_string(i), val1));
        EXPECT_TRUE(b.insert("Key" + std::to_string(i), val1));
    }
    for (int i = 0; i < 500; ++i) {
        EXPECT_TRUE(a.contains("Key" + std::to_string(i)));
        EXPECT_TRUE(b.contains("Key" + std::to_string(i)));
    }
    EXPECT_TRUE(a == b);
    for (int i = 0; i < 500; ++i) {
        val2.age = std::rand()%100;
        val2.weight = std::rand()%100;
        EXPECT_TRUE(a.insert("Key" + std::to_string(i), val1));
        EXPECT_TRUE(b.insert("Key" + std::to_string(i * 3), val2));
    }
    for (int i = 0; i < 500; ++i) {
        EXPECT_TRUE(a.contains("Key" + std::to_string(i)));
        EXPECT_TRUE(b.contains("Key" + std::to_string(i * 3)));
    }
    EXPECT_FALSE(a == b);
    HashTable c;
    HashTable d;
    c.insert("Key1", val1);
    d.insert("Key2", val2);
    EXPECT_FALSE(c == d);
}

TEST(HashTableTest, OperatorNotEq) {
    HashTable a;
    HashTable b;
    Value val1;
    Value val2;
    for (int i = 0; i < 500; ++i) {
        val1.age = std::rand()%100;
        val1.weight = std::rand()%100;
        EXPECT_TRUE(a.insert("Key" + std::to_string(i), val1));
        EXPECT_TRUE(b.insert("Key" + std::to_string(i), val1));
    }
    for (int i = 0; i < 500; ++i) {
        EXPECT_TRUE(a.contains("Key" + std::to_string(i)));
        EXPECT_TRUE(b.contains("Key" + std::to_string(i)));
    }
    EXPECT_FALSE(a != b);
    for (int i = 0; i < 500; ++i) {
        val2.age = std::rand()%100;
        val2.weight = std::rand()%100;
        EXPECT_TRUE(a.insert("Key" + std::to_string(i), val1));
        EXPECT_TRUE(b.insert("Key" + std::to_string(i * 3), val2));
    }
    for (int i = 0; i < 500; ++i) {
        EXPECT_TRUE(a.contains("Key" + std::to_string(i)));
        EXPECT_TRUE(b.contains("Key" + std::to_string(i * 3)));
    }
    EXPECT_TRUE(a != b);
}

TEST(HashTableTest, Swap) {
    HashTable a;
    HashTable b;
    Value val1;
    Value val2;
    EXPECT_TRUE(a.empty());
    for (int i = 0; i < 500; ++i) {
        val1.age = std::rand()%100;
        val1.weight = std::rand()%100;
        val2.age = std::rand()%100;
        val2.weight = std::rand()%100;
        EXPECT_TRUE(a.insert("key" + std::to_string(i), val1));
        EXPECT_TRUE(b.insert("key" + std::to_string(i * 3), val2));
    }
    for (int i = 0; i < 500; ++i) {
        EXPECT_TRUE(a.contains("key" + std::to_string(i)));
        EXPECT_TRUE(b.contains("key" + std::to_string(i * 3)));
    }
    HashTable buf1 = a;
    HashTable buf2 = b;
    a.swap(b);
    EXPECT_TRUE(a == buf2);
    EXPECT_TRUE(b == buf1);
}

TEST(HashTableTest, At) {
    HashTable a;
    Value val;
    val.age = std::rand()%100;
    val.weight = std::rand()%100;
    a.insert("Key", val);
    ASSERT_NO_THROW(a.at("Key"));
    ASSERT_THROW(a.at("NotKey"), std::out_of_range);
    EXPECT_EQ(val.age, a.at("Key").age);
    EXPECT_EQ(val.weight, a.at("Key").weight);
}

TEST(HashTableTest, ConAt) {
    HashTable a;
    Value val;
    val.age = std::rand()%100;
    val.weight = std::rand()%100;
    a.insert("Key", val);
    const HashTable b = a;
    ASSERT_NO_THROW(b.at("Key"));
    ASSERT_THROW(b.at("NotKey"), std::out_of_range);
    EXPECT_EQ(val.age, b.at("Key").age);
    EXPECT_EQ(val.weight, b.at("Key").weight);
}

TEST(HashTableTest, SquBr) {
    HashTable a;
    Value val;
    val.age = std::rand()%100;
    val.weight = std::rand()%100;
    a.insert("Key", val);
    a["NotKey"];
    ASSERT_NO_THROW(a["Key"]);
    EXPECT_EQ(val.age, a["Key"].age);
    EXPECT_EQ(val.weight, a["Key"].weight);
}

TEST(HashTableTest, Assignment) {
    HashTable a;
    HashTable b;
    Value val;
    val.age = std::rand()%100;
    val.weight = std::rand()%100;
    b.insert("Key", val);
    a = b;
    EXPECT_TRUE(a == b);
}

