require 'date'

# QWASAR.IO -- my_data_transform
# @param {String} param_1
# @return {string[]}
def my_data_transform(param_1)
  # Split the input CSV string into lines
  lines = param_1.split("\n")

  # Prepare an array to hold the transformed data
  transformed_data = []

  # Get the header and add it to the transformed data
  header = lines[0]
  transformed_data << header

  # Process each line after the header
  lines[1..-1].each do |line|
    columns = line.split(",")

    # Extract email and get the provider
    email = columns[4]
    email_provider = email.split("@").last

    # Extract age and categorize it
    age = columns[5].to_i
    age_group = case age
                when 1..20 then "1->20"
                when 21..40 then "21->40"
                when 41..65 then "41->65"
                when 66..99 then "66->99"
                else ""
                end

    # Extract order time and categorize it
    order_time_str = columns[8].strip # Ensure we remove any whitespace
    begin
      order_time = DateTime.parse(order_time_str)
    rescue ArgumentError => e
      puts "Date parsing error: #{order_time_str}" # Debugging output
      next # Skip this record if the date is invalid
    end

    order_group = case order_time.hour
                  when 6..11 then "morning"
                  when 12..17 then "afternoon"
                  when 18..23 then "evening"
                  else ""
                  end

    # Build the transformed line and add it to the array
    transformed_line = [
      columns[0], # Gender
      columns[1], # FirstName
      columns[2], # LastName
      columns[3], # UserName
      email_provider, # Email provider only
      age_group, # Age group
      columns[6], # City
      columns[7], # Device
      columns[8], # Coffee Quantity
      order_group # Order At
    ].join(",")

    transformed_data << transformed_line
  end

  # Return the transformed data as an array of strings
  transformed_data
end
