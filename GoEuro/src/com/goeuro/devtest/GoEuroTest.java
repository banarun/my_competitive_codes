package com.goeuro.devtest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Objects;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import com.google.common.net.UrlEscapers;
import com.google.gson.Gson;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.reflect.TypeToken;

public class GoEuroTest {

	private final static String SEPERATOR = ",";
	private final static String NEW_LINE = "\n";
	private final static String END_POINT_PREFIX = "http://api.goeuro.com/api/v2/position/suggest/en/";
	private final static String OUTPUT_FILE_NAME = "./output.csv";
	private final static String CSV_HEADER = "_id,name,type,latitude,longitude";

	public static void main(String[] args) throws IOException {
		long startTime = System.currentTimeMillis();
		validateInput(args);
		System.out.println("City name passed "+args[0]);		
		String cityName = UrlEscapers.urlPathSegmentEscaper().escape(args[0]);

		String responseFromEndPoint = fetchDataFromEndpoint(END_POINT_PREFIX + cityName);

		System.out.println("Number of bytes received from endpoint " + responseFromEndPoint.length());

		List<JsonObject> listOfJsonObjects = new Gson().fromJson(responseFromEndPoint,
				new TypeToken<List<JsonObject>>() {
				}.getType());
		
		System.out.println("Number of entries fetched from endpoint "+listOfJsonObjects.size());
		String outputAsCSVString = CSV_HEADER + NEW_LINE +
				listOfJsonObjects.stream()
					.peek(Objects::requireNonNull)
					.flatMap(jsonObjectToCSVRow)
					.collect(Collectors.joining());

		Files.write(Paths.get(OUTPUT_FILE_NAME), outputAsCSVString.getBytes());
		System.out.println("Written output to file " + OUTPUT_FILE_NAME);
		System.out.println("Total time taken for execution: "+(System.currentTimeMillis() - startTime)+" milliseconds");
	}

	/**
	 * Method to make a call to the end point provided and return the response
	 * 
	 * @param Endpoint
	 *            to make a request
	 * @return the response from the end point as string
	 * @throws IllegalStateException
	 *             when an exception has occurred while making a request.
	 *             Exception cause is wrapped inside.
	 */
	public static String fetchDataFromEndpoint(String endPoint) throws IllegalStateException {
		try {
			System.out.println("Getting data from endpoint "+endPoint);
			URL url = new URL(endPoint);
			HttpURLConnection conn = (HttpURLConnection) url.openConnection();
			conn.setRequestMethod("GET");

			if (conn.getResponseCode() != 200) {
				throw new IllegalStateException("Server responded with error for the given city name. HTTP error code : " + conn.getResponseCode());
			}

			BufferedReader br = new BufferedReader(new InputStreamReader((conn.getInputStream())));

			Objects.requireNonNull(br.lines(), "No data was fetched from the endpoint");

			// Copy the entire response data into a String object
			String output = br.lines().collect(Collectors.joining(NEW_LINE));
			
			conn.disconnect();

			return output;

		} catch (MalformedURLException e) {
			throw new IllegalStateException("Exception occurred while calling the endpoint. ", e);
		} catch (IOException e) {
			throw new IllegalStateException("IOException occurred. ", e);
		}
	}

	/**
	 * Method to validate that the input passed by the client is as expected by
	 * the application
	 * 
	 * @param Input
	 *            that has been passed
	 * @throws IllegalArgumentException
	 *             when the input passed is incorrect
	 */
	private static void validateInput(String[] args) {
		if (args.length == 0 || args[0].isEmpty()) {
			String errorMessage = "City name should be passed as an argument";
			System.err.println(errorMessage);
			throw new IllegalArgumentException(errorMessage);
		}
	}

	/**
	 * Function used to map each json object to a string stream that is used for
	 * constructing output csv
	 */
	public static Function<JsonObject, Stream<String>> jsonObjectToCSVRow = (entry) -> {

		JsonElement name = Objects.requireNonNull(entry.get(JsonConstants.NAME), "name cannot be null");
		JsonObject geoPosition = Objects.requireNonNull(entry.getAsJsonObject(JsonConstants.GEO_POSITION),
				"Geo position cannot be null");

		return Stream.of(
				entry.get(JsonConstants.ID).getAsString(), SEPERATOR, 
				name.getAsString(), SEPERATOR,
				entry.get(JsonConstants.TYPE).getAsString(), SEPERATOR,
				geoPosition.get(JsonConstants.LATITUDE).getAsString(), SEPERATOR,
				geoPosition.get(JsonConstants.LONGITUDE).getAsString(), 
				NEW_LINE );
	};
}