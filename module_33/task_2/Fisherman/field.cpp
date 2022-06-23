#include "field.h"


Field::Field()
{
    content = Content::FREE;
}

Field &Field::operator=(const Content &inContent)
{
    content = inContent;
    return *this;
}

void Field::fishing()
{
    if(content == Content::BOOT)
        throw Failure();
    if(content == Content::FISH)
        throw Fortune();
}

Content Field::get()
{
    return content;
}
