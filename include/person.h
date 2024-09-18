#ifndef PERSON_H
#define PERSON_H

class Person {
    public:
        Person(int height, int weight);
        int getHeight() const;
        int getWeight() const;
    private:
        int height_;
        int weight_;
};

#endif // PERSON_H