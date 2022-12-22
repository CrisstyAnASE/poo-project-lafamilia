#pragma once
#include <string>

enum ExceptionType {
	INVALID_COMMAND, 
	INVALID_ARGUMENT, 
	INVALID_ARGUMENT_TYPE,
	INVALID_DEFAULT_VALUE,
	PARANTHESIS_MISMATCH,
	NO_FIELDS_SELECTED,
	INVALID_COMMAS,
	FORBIDDEN_WORDS_USED,
	INVALID_FIELD,
	INVALID_TABLE_NAME,
	INVALID_INDEX_NAME,
	INVALID_COLUMN_NAME,
	INVALID_QUTES,
	EMPTY_CONDITION_OR_ARGUMENT,
	NO_FILES_PASSED,
	FILE_DOES_NOT_EXIST
};

class Exceptions : public std::exception {
	ExceptionType exceptionType;
public:
	Exceptions(ExceptionType exceptionType) {
		this->exceptionType = exceptionType;
	}
	std::string handleError() {
		switch (exceptionType)
		{
		case INVALID_COMMAND:
			return "You entered an invalid command. Please type again:\n";
		case INVALID_ARGUMENT:
			return "You entered an invalid argument. Please type again:\n";
		case INVALID_ARGUMENT_TYPE:
			return "The argument you entered has an invalid type. Please type again:\n";
		case INVALID_DEFAULT_VALUE:
			return "The argument you entered has an invalid default value. Please type again:\n";
		case NO_FIELDS_SELECTED:
			return "No fields selected. Please type again:\n";
		case INVALID_COMMAS:
			return "Invalid commas. Please type again:\n";
		case FORBIDDEN_WORDS_USED: // like CREATE, TABLE, UPDATE, INDEX, SELECT, INSERT, INTO, DROP, DISPLAY, DELETE, FROM, WHERE, SET 
			return "Cannot have fields or tables named with forbidden words. Please type again:\n"; // remains to implement
		case PARANTHESIS_MISMATCH: // check if the number of ( equals the number of ) in the rawInput
			return "You missmatched paranthesis. Please type again:\n"; // remains to implement
		case INVALID_QUTES: // the number of " should be even in rawInput
			return "You mismatched the quotes. Please type again:\n";
		case INVALID_FIELD:
			return "Invalid field passed. Please type again:\n";
		case INVALID_TABLE_NAME:
			return "Invalid table name. Please type again:\n";
		case INVALID_INDEX_NAME:
			return "Invalid index name. Please type again:\n";
		case INVALID_COLUMN_NAME:
			return "Invalid column name. Please type again:\n";
		case EMPTY_CONDITION_OR_ARGUMENT:
			return "Empty condition or argument. Please type again.\n";
		case NO_FILES_PASSED:
			return "You forgot pass at least 1 file.\n";
		case FILE_DOES_NOT_EXIST:
			return "One of the passed files doesn't exist.\n";
		default:
			break;
		}
	}

};
