#include <domain/model/base/AggregateRoot.h>

AggregateRoot::AggregateRoot(const std::string& id) : id(id)
{

}

bool AggregateRoot::operator==(const AggregateRoot* rhs)
{
	return id == rhs->id;
}

bool AggregateRoot::operator!=(const AggregateRoot* rhs)
{
	return !operator==(rhs);
}

std::string AggregateRoot::getId() const
{
	return id;
}
